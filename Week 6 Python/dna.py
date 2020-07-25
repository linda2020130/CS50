from sys import argv, exit
from csv import reader

# Report error if didn't receive 2 command-line arguments
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

# Read csv file and store in database
with open(argv[1], newline='') as csvFile:
    database = list(reader(csvFile))

# Read txt file and store in sequence
with open(argv[2]) as txtFile:
    sequence = txtFile.read()

# Count the number of times each of the STRs consecutively repeated in the sequence
check = ['unknown']
for i in range(len(database[0]) - 1):
    # Check each substring in the sequence with length of the STR
    match = []
    for j in range(len(sequence) - len(database[0][i + 1]) - 1):
        if database[0][i + 1] == sequence[j: j + len(database[0][i + 1])]:
            match.append(j)
    if len(match) > 1:
        count = 1
        tmp = []
        for k in range(len(match) - 1):
            if match[k] + len(database[0][i + 1]) == match[k + 1]:
                count += 1
            else:
                tmp.append(count)
                count = 1
        tmp.append(count)
        check.append(str(max(tmp)))
    elif len(match) == 1:
        check.append('1')
    else:
        check.append('0')
        
# Find the person who matches the number of repeated times for each of the STRs
for i in range(len(database) - 1):
    if database[i + 1][1:] == check[1:]:
        print(database[i + 1][0])
        exit(0)
print("No match")
