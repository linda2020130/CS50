from cs50 import get_float

cash = -1
while cash < 0:
    cash = get_float("Change owed: ")
    
# Round up to cents so no need to check if user's input is too large to fit in a float
cents = round(cash * 100)
a = 0
b = 0
c = 0
d = 0
# How many 25 cents?
while cents >= 25:
    cents -= 25
    a += 1
# How many 10 cents?
while cents >= 10:
    cents -= 10
    b += 1
# How many 5 cents?
while cents >= 5:
    cents -= 5
    c += 1
# How many 1 cent?
while cents >= 1:
    cents -= 1
    d += 1

print(a + b + c + d)
    
