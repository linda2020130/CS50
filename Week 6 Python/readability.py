from cs50 import get_string

text = get_string("Text: ")
length = len(text)

# Get letter counts from given text, only a-z or A-Z are considered as a letter
letter = 0
for i in range(length):
    if text[i] >= "a" and text[i] <= "z":
        letter += 1
    elif text[i] >= "A" and text[i] <= "Z":
        letter += 1

# Get word counts from given text, only consider characters separated by a space to be a word
word = 0
for i in range(length):
    if text[i] == " ":
        word += 1
word += 1    # Last word

# Get sentence count from given text, 
# only consider characters that ends with '.' or '!' or '?' to be a sentence
sentence = 0
for i in range(length):
    if text[i] in [".", "!", "?"]:
        sentence += 1

# Calculate Coleman-Liau index
L = 100 * (letter / word)
S = 100 * (sentence / word)
index = round(0.0588 * L - 0.296 * S - 15.8)

if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade " + str(index))
