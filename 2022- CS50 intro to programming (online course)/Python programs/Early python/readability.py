# TODO
import cs50 as cs
# Program reads an input and calculates the readability grade


text = cs.get_string("Text: ")

letters = 0
words = 1
sentences = 0

# Count letters, spaces and periods
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1

    if text[i] == ' ':
        words += 1

    if text[i] == "." or text[i] == "?" or text[i] == '!':
        sentences += 1

grade = round((5.88 * letters - 29.6 * sentences) / words - 15.8)

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print("Grade ", end="")
    print(grade)