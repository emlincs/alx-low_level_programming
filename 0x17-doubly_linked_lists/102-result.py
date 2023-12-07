#!/usr/bin/python3

largest_palindrome = 0

for k in range(100, 1000):
    for m in range(100, 1000):
        product = k * m
        if str(product) == str(product)[::-1] and product > largest_palindrome:
            largest_palindrome = product

with open("102-result", "w") as file:
    file.write(str(largest_palindrome))


