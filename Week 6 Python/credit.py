from cs50 import get_string

credit = get_string("Number: ")
N = len(credit)
# Total of odd digits
if N % 2 == 1:
    # odd digits are in index 0, 2, 4, ...
    # even digits are in index 1, 3, 5, ...
    m = 0
    n = 1
# Total of even digits
else:
    # odd digits are in index 1, 3, 5, ...
    # even digits are in index 0, 2, 4, ...
    m = 1
    n = 0

sum_odd = 0
# sum_odd is sum of odd digits in credit card number (even position in the array)
for i in range(m, N, 2):
    sum_odd += int(credit[i])

sum_even = 0
# sum_even is sum of (2 * even digits) in credit card number (odd position in the array)
for i in range(n, N, 2):
    if int(credit[i]) < 5:
        sum_even += 2 * int(credit[i])
    else:
        sum_even += 1 + (2 * int(credit[i])) % 10

# Check if credit card is valid
if (sum_odd + sum_even) % 10 == 0:
    # Check if number is American Express
    # Length is 15 and start with 34 or 37
    if N == 15 and int(credit[0]) == 3 and int(credit[1]) in [4, 7]:
        print("AMEX")
    # Check if number is Visa
    # Length is 13 or 16 and start with 4
    elif N in [13, 16] and int(credit[0]) == 4:
        print("VISA")
    # Check if number is MasterCard
    # Length is 16 and start with 51, 52, 53, 54, or 55
    elif N == 16 and int(credit[0]) == 5 and int(credit[1]) in [1, 2, 3, 4, 5]:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
