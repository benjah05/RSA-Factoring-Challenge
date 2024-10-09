#!/usr/bin/python3
"""Import sys to access sys functions like argv, exit, etc."""
import sys
"""Import math to access math function like sqrt"""
import math


def factors():
    """Factorize a number into 2 smaller numbers"""
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)
    try:
        with open(sys.argv[1], "r") as numfile:
            for num in numfile:
                n = int(num.strip())
                for i in range(2, math.isqrt(num) + 1):
                    if n % i == 0:
                        print("{}={}*{}".format(n, n // i, i))
                        break
    except FileNotFoundError:
        print("File not found")
        sys.exit(1)

if __name__ == "__main__":
    factors()
