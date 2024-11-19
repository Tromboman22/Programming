# TODO
import cs50 as cs


number = cs.get_int("Card number: ")
n = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
total = 0

for i in range(16):
    while number >= 10**(15 - i):
        number -= 10**(15 - i)
        n[i] += 1

    if i % 2 == 0:
        if (2 * n[i]) > 9:
            total += (2 * n[i]) - 9
        else:
            total += 2 * n[i]
    else:
        total += n[i]

if total % 10 != 0:
    print("INVALID")
else:
    if n[0] == 4:
        print("VISA")
    elif n[0] == 0 and n[1] == 0 and n[2] == 0 and n[3] == 4:
        print("VISA")
    elif n[0] == 0 and n[1] == 3:
        if n[2] == 4 or n[2] == 7:
            print("AMEX")
        else:
            print("INVALID")
    elif n[0] == 5:
        if 0 < n[1] and n[1] < 6:
            print("MASTERCARD")
        else:
            print("INVALID")
    else:
        print("INVALID")
