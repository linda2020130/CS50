from sys import argv, exit
from cs50 import SQL

# Report error if didn;t receive the name of a house as a command-line argument
if len(argv) != 2:
    print("Usage: python roster.py houseName")
    exit(1)

# Get access to a sqlite database
db = SQL("sqlite:///students.db")

# Query the students table in the students.db database for all of the students in the specified house
rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", argv[1])

# Print out each student on their own line
for row in rows:
    if row["middle"] == None:
        print("{0} {1}, born {2}".format(row["first"], row["last"], row["birth"]))
    else:
        print("{0} {1} {2}, born {3}".format(row["first"], row["middle"], row["last"], row["birth"]))
