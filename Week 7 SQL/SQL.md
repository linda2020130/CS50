## SQL

* SQL(the *Structured Query Language*) is a programming language whose purpose is to **query** a database.
* **MySQL** is one open-source platform on which you can establish the type of relational database that SQL is most adept at working with.
  * **SQLite** is another, which we've actually use in CS50 since 2016.
* Many installations of SQL come with a GUI tool called **phpMyAdmin** which can be used to execute database queries in a more user-friendly way.
* Each column of your SQL table is capable of holding data of a particular data type.
* SQLite is one database application that supports SQL, and there are many companies with server applications that support SQL, includes Oracle Database, MySQL, PostgreSQL, MariaDB, and Microsoft Access.
* SQL integrates with other programming languages such as Python or PHP very easily.
* With `.schema`, we can see how the format for the table for our data is created.

<br />

### Data Types

* `BLOB`: short for **binary large object**, raw binary data that might represent files.
* `INTEGER`
 * `smallint`
 * `integer`
 * `bigint`
* `NUMERIC`
 * `boolean`
 * `date`
 * `datetime`
 * `numeric(scale, precision)`: which solves floating-point imprecision by using as many bits as needed, for each digit before and after the decimal point.
 * `time`
 * `timestamp`
* `REAL`
 * `real`: for floating-point values
 * `double precision`: with more bits
* `TEXT`
 * `char(n)`: for an exact number of characters
 * `varchar(n)`: for a variable number of characters, up to a certain limit
 * `text`
 
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

* There are also other operations we can combine as needed:
  * `WHERE`: matching on some strict condition
  * `LIKE`: matching on substrings for text
  * `LIMIT`
  * `GROUP BY`
  * `ORDER BY`
  * `JOIN`: combining data from multiple tables

#### INSERT

* Add information to a table.
```sql
INSERT INTO
<table>
(<columns>)
VALUES
(<values>)
```

e.g.
```sql
INSERT INTO
users
(username, password, fullname)
VALUES
('newman', 'USMAIL', 'Newman')
```

* After inserting values, we can use functions to perform calculations.
 * `AVG`
 * `COUNT`
 * `DISTINCT`: for getting distinct values without duplicates
 * `MAX`
 * `MIN`

#### SELECT

* Extract information from a table.
```sql
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
```sql
SELECT
idnum, fullname
FROM
users
WHERE
idnum < 12
```

* Extract information from two tables
```sql
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
```sql
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
```sql
UPDATE
<table>
SET
<column> = <value>
WHERE
<predicate>
```

e.g.
```sql
UPDATE
users
SET
password = 'yadayada'
WHERE
idnum = 10
```

e.g.
```sql
UPDATE
favorites
SET
title = 'The office'
WHERE
title LIKE '%office'
```

#### DELETE

* Remove information from a table
```sql
DELETE FROM
<table>
WHERE
<predicate>
```

e.g.
```sql
DELETE FROM
users
WHERE
username = 'newman'
```

* We can even delete an entire table altogether with another command, `DROP`.
