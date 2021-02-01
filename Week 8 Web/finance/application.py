import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    id = session.get("user_id")

    # Look up username
    row = db.execute("SELECT username FROM users WHERE id = :id", id=id)
    username = row[0]["username"]

    # Look up how much cash the user currently has
    row = db.execute("SELECT cash FROM users WHERE id = :id", id=id)
    cash = row[0]["cash"]

    # Look up summary data
    summaryDT = db.execute("SELECT symbol_trans, totalshares, aveprice FROM summary WHERE id_users = :id " +
                           "ORDER BY symbol_trans", id=id)
    table = []
    total = cash
    for row in summaryDT:
        if row["totalshares"] != 0:
            price = lookup(row["symbol_trans"])["price"]
            diff = round(price - row["aveprice"], 2)
            if diff >= 0:
                color = "green"
                diff = "+" + str(diff)
            else:
                color = "red"
            values = row["totalshares"] * price
            total += values
            table.append({"symbol": row["symbol_trans"], "shares": row["totalshares"], "avePrice": usd(row["aveprice"]),
                          "price": usd(price), "diff": diff,"values": usd(values), "color": color})

    return render_template("index.html", table=table, username=username, cash=usd(cash), total=usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure symbol was submitted
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 403)

        # Look up a stock's current price
        quoted = lookup(symbol)

        # Ensure symbol is valid
        if quoted == None:
            return apology("must provide valid symbol", 403)
        symbol = symbol.upper()

        # Ensure shares was submitted
        shares = request.form.get("shares")
        if not shares:
            return apology("must provide number of shares", 403)

        # Ensure shares is a positive integer
        try:
            shares = float(shares)
        except ValueError:
            return apology("must provide a positive integer", 403)

        if shares % 1 != 0 or shares <= 0:
            return apology("must provide a positive integer", 403)

        # Look up how much cash the user currently has
        id = session.get("user_id")
        row = db.execute("SELECT cash FROM users WHERE id = :id", id=id)

        # Purchase failed if not enough cash
        price = quoted["price"]
        cash = row[0]["cash"]
        if cash < price * shares:
            return apology("not enough cash", 403)

        # Insert new transaction into trans
        db.execute("INSERT INTO trans (id_users, symbol, price, shares, type) " +
                   "VALUES (:id_users, :symbol, :price, :shares, :type)",
                   id_users=id, symbol=symbol, price=price, shares=shares, type="buy")

        # Update cash balance after transaction success
        db.execute("UPDATE users SET cash=:cash WHERE id=:id", cash=cash-price*shares, id=id)

        # Update summary table after transaction success
        summary = db.execute("SELECT aveprice, totalshares FROM summary WHERE id_users=:id AND symbol_trans=:symbol",
                             id=id, symbol=symbol)
        if len(summary) == 0:
            db.execute("INSERT INTO summary (id_users, symbol_trans, aveprice, totalshares) " +
                       "VALUES (:id, :symbol, :aveprice, :totalshares)",
                       id=id, symbol=symbol, aveprice=price, totalshares=shares)
        else:
            totalshares = summary[0]["totalshares"] + shares
            aveprice = round((summary[0]["aveprice"] * summary[0]["totalshares"] + price * shares) / totalshares,2)
            db.execute("UPDATE summary SET aveprice=:aveprice, totalshares=:totalshares " +
                       "WHERE id_users=:id AND symbol_trans=:symbol",
                       aveprice=aveprice, totalshares=totalshares, id=id, symbol=symbol)

        # Redirect user to home page
        flash("Transaction Success!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    id = session.get("user_id")

    # Get symbol
    symbol = request.args.get("symbol")

    # Look up username
    if symbol != None:
        rows = db.execute("SELECT type, symbol, price, shares, time FROM trans WHERE id_users = :id AND " +
                          "symbol = :symbol ORDER BY time", id=id, symbol=symbol)
    else:
        rows = db.execute("SELECT type, symbol, price, shares, time FROM trans WHERE id_users = :id " +
                          "ORDER BY time", id=id)

    return render_template("history.html", id=id, rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    if session.get("user_id"):
        session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        username = request.form.get("username")
        if not username:
            return apology("must provide username", 403)

        # Ensure password was submitted
        pwd = request.form.get("password")
        if not pwd:
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=username)

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], pwd):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        flash("Log In Success!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/changepwd", methods=["GET", "POST"])
@login_required
def changepwd():
    """Let user change password"""

    id = session.get("user_id")
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Query database for username
        rows = db.execute("SELECT hash FROM users WHERE id = :id", id=id)

        # Check original password
        oldpwd = request.form.get("oldpassword")
        if not check_password_hash(rows[0]["hash"], oldpwd):
            return apology("original password not correct", 403)

        # Ensure new password was not blank
        newpwd = request.form.get("newpassword")
        if not newpwd:
            return apology("password can't be blank", 403)

        # Ensure original and new password not the same
        elif oldpwd == newpwd:
            return apology("password can't be the same", 403)

        # Ensure confirmation was not blank
        confirm = request.form.get("confirmation")
        if not confirm:
            return apology("confirmation can't be blank", 403)

        # Ensure new password equals to confirmation
        elif newpwd != confirm:
            return apology("confirmation and password are not the same", 403)

        # Update hash
        db.execute("UPDATE users SET hash=:hash WHERE id=:id", hash=generate_password_hash(newpwd), id=id)

        # Redirect user to home page
        flash("Password Change Success!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("changepwd.html")

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    flash("Log Out Success!")
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Get quoted info from lookup function
        quoted = lookup(request.form.get("symbol"))
        if quoted == None:
            return apology("must provide valid symbol", 403)
        else:
            return render_template("quoted.html", name=quoted["name"],
                                   price=usd(quoted["price"]), symbol=quoted["symbol"])

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was not blank
        username = request.form.get("username")
        if not username:
            return apology("username can't be blank", 403)

        # Ensure password was not blank
        password = request.form.get("password")
        if not password:
            return apology("password can't be blank", 403)

        # Ensure confirmation was not blank
        confirmation = request.form.get("confirmation")
        if not confirmation:
            return apology("confirmation can't be blank", 403)

        # Ensure password equals to confirmation
        if password != confirmation:
            return apology("confirmation and password are not the same", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=username)

        # Ensure username hasn't registered yet
        if len(rows) != 0:
            return apology("username has been registered", 403)

        # Insert new user to users
        db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                   username=username, hash=generate_password_hash(password))

        # Redirect user to home page
        flash("Registration Success!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure symbol was submitted
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide symbol", 403)

        # Look up a stock's current price
        quoted = lookup(symbol)

        # Ensure symbol is valid
        if quoted == None:
            return apology("must provide valid symbol", 403)

        # Look up number of shares in buy and sell data
        id = session.get("user_id")
        buyDT = db.execute("SELECT shares FROM trans WHERE id_users = :id AND type = 'buy' AND symbol = :symbol"
                           , id=id, symbol=symbol)
        sellDT = db.execute("SELECT shares FROM trans WHERE id_users = :id AND type = 'sell' AND symbol = :symbol"
                           , id=id, symbol=symbol)
        # Compute current shares' balance
        balance = 0
        for row in buyDT:
            balance += row["shares"]

        for row in sellDT:
            balance -= row["shares"]

        # Ensure user owns any shares of this stock
        if balance == 0:
            return apology("do not have this stock", 403)

        # Ensure shares was submitted
        shares = request.form.get("shares")
        if not shares:
            return apology("must provide number of shares", 403)

        # Ensure shares is a positive integer
        try:
            shares = float(shares)
        except ValueError:
            return apology("must provide a positive integer", 403)

        if shares % 1 != 0 or shares <= 0:
            return apology("must provide a positive integer", 403)

        # Ensure user owns that many of shares
        if shares > balance:
            return apology("not enough shares", 403)

        # Look up how much cash the user currently has
        row = db.execute("SELECT cash FROM users WHERE id = :id", id=id)
        cash = row[0]["cash"]
        price = quoted["price"]

        # Insert new transaction into trans
        db.execute("INSERT INTO trans (id_users, symbol, price, shares, type) " +
                   "VALUES (:id_users, :symbol, :price, :shares, :type)",
                   id_users=id, symbol=symbol, price=price, shares=shares, type="sell")

        # Update cash balance after transaction success
        db.execute("UPDATE users SET cash=:cash WHERE id=:id", cash=cash+price*shares, id=id)

        # Update summary table after transaction success
        summary = db.execute("SELECT aveprice, totalshares FROM summary WHERE id_users=:id AND symbol_trans=:symbol",
                             id=id, symbol=symbol)
        totalshares = summary[0]["totalshares"] - shares
        if totalshares == 0:
            aveprice = 0
        else:
            aveprice = round((summary[0]["aveprice"] * summary[0]["totalshares"] - price * shares) / totalshares,2)

        db.execute("UPDATE summary SET aveprice=:aveprice, totalshares=:totalshares " +
                   "WHERE id_users=:id AND symbol_trans=:symbol",
                   aveprice=aveprice, totalshares=totalshares, id=id, symbol=symbol)

        # Redirect user to home page
        flash("Transaction Success!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        id = session.get("user_id")

        # Look up buy and sell data
        buyDT = db.execute("SELECT symbol, SUM(shares) FROM trans WHERE id_users = :id AND type = 'buy' " +
                           "GROUP BY symbol ORDER BY symbol", id=id)
        sellDT = db.execute("SELECT symbol, SUM(shares) FROM trans WHERE id_users = :id AND type = 'sell' " +
                           "GROUP BY symbol ORDER BY symbol", id=id)

        # Calculate current shares balance
        dic = {}
        for row in buyDT:
            dic[row["symbol"]] = row["SUM(shares)"]

        for row in sellDT:
            dic[row["symbol"]] -= row["SUM(shares)"]

        # Generate summary table
        menu = []
        for symbol, shares in dic.items():
            if shares > 0:
                menu.append({"symbol": symbol, "shares": shares})

        return render_template("sell.html", menu=menu)


# Check if user input is valid
@app.route("/api/id/check", methods=["POST"])
def check_username():
    username = request.form.get("username")
    # Query database for username
    if username and username != "" and request.method == "POST":
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=username)
        if len(rows) != 0:
            resp = jsonify("<img src=\'static/invalid.png\' height=18 width=18>"
                   + "<span style=\'color: #e60000;\'> username registered</span>")
        else:
            resp = jsonify("<img src=\'static/valid.png\' height=18 width=18>"
                   + "<span style=\'color: #00cc00;\'> username valid</span>")
    else:
        resp = jsonify("<img src=\'static/invalid.png\' height=18 width=18>"
                   + "<span style=\'color: #e60000;\'>username required</span>")

    resp.status_code = 200
    return resp



def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
