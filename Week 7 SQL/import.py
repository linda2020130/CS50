from sys import argv, exit
from cs50 import SQL
import csv

# Report error if didn't receive the name of a CSV file as a command-line argument
if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

# Get access to a sqlite database
db = SQL("sqlite:///students.db")

# Open CSV file
with open(argv[1], "r", newline='') as file:

    # Create DictReader
    # DictReader will automatically assume first row as header
    reader = csv.DictReader(file)

    # Iterate over CSV file
    for row in reader:
        name = row["name"]

        # Split the name to first, middle, and last name
        nameList = name.split(' ')
        firstName = nameList[0]
        if len(nameList) == 2:
            middleName = None
            lastName = nameList[1]
        else:
            middleName = nameList[1]
            lastName = nameList[2]

        # Insert each row into the table
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   firstName, middleName, lastName, row['house'], row['birth'])
