## SQL

* SQL(the *Structured Query Language*) is a programming language whose purpose is to **query** a database.
* **MySQL** is one open-source platform on which you can establish the type of relational database that SQL is most adept at working with.
  * **SQLite** is another, which we've actually use in CS50 since 2016.
* Many installations of SQL come with a GUI tool called **phpMyAdmin** which can be used to execute database queries in a more user-friendly way.
* Each column of your SQL table is capable of holding data of a particular data type.
  * e.g. `INT`, `DECIMAL`, `FLOAT`, `DATE`, `CHAR`, `VARCHAR`, `TEXT`, ......
* SQL integrates with other programming languages such as Python or PHP very easily.
 
<br />

### CHAR vs. VARCHAR

* Unlike in C, the `CHAR` data type in SQL does not refer to a single character. Rather, it is a fixed-length string.
  * In most relational databases, including MySQL, you actually specify the **fixed-length** as part of the type definition, e.g. CHAR(10).
* A `VARCHAR` refers to a variable-length string.
  * VARCHARs also require you to specify the **maximum** possible length of a string that could be stored in that column, e.g. VARCHAR(99).

<br />

### Data Types of SQLite

* SQLite has these data types as well, but affiliates each with a "type affinity" to simplify things.
  * `NULL`: Nothing
  * `INTEGER`: Whole numbers
  * `REAL`: Numbers including decimal and float.
  * `TEXT`: Things including char and varchar.
  * `BLOB`: Things like the geometry or data that isn't really text, but just a large number of bits or bytes.

<br />

### Primary Key

* One other important consideration when constructing a table in SQL is to choose one column to be your **primary key**.
* Primary keys enable rows of a table to be uniquely and quickly identified.
* It is also possible to establish a **joint primary key** - a combination of two columns that is always guaranteed to be unique.
* It is usually a good idea to have primary key's column be an integer.
* You can configure that column to **autoincrement**, so it will pre-populate that column for you automatically when rows are added to the table.

<br />

### Four Operations

* We will primarily consider just **four** operations that one may perform on a table.
1. **INSERT**
2. **SELECT**
3. **UPDATE**
4. **DELETE**

#### INSERT

* Add information to a table.
```
INSERT INTO
<table>
(<columns>)
VALUES
(<values>)
```

e.g.
```
INSERT INTO
users
(username, password, fullname)
VALUES
('newman', 'USMAIL', 'Newman')
```

#### SELECT

* Extract information from a table.
```
SELECT
<columns>
FROM
<table>
WHERE
<condition>
ORDER BY
<column>
```

e.g.
```
SELECT
idnum, fullname
FROM
users
WHERE
idnum < 12
```

* Extract information from two tables
```
SELECT
<columns>
FROM
<table1>
JOIN
<table2>
ON
<predicate>
```

e.g.
```
SELECT
users.fullname, moms.mother
FROM
users
JOIN
moms
ON
users.username = moms.username
```

#### UPDATE

* Mondify information in a table.
```
UPDATE
<table>
SET
<column> = <value>
WHERE
<predicate>
```

e.g.
```
UPDATE
users
SET
password = 'yadayada'
WHERE
idnum = 10
```

#### DELETE

* Remove information from a table
```
DELETE FROM
<table>
WHERE
<predicate>
```

e.g.
```
DELETE FROM
users
WHERE
username = 'newman'
```
