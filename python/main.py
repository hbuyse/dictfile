#! /usr/bin/env python

__author__ = "Henri Buyse"
__mail__   = "henri.buyse@gmail.com"


import os
import sys

def listWords(path):
    words = []

    with open(path, 'r') as f:
        words = [l.strip('\n') for l in f.readlines() if l.strip('\n') != '']

    for word in words:
        if word[0] == "#":
            words.remove(word)

    compte = {word: words.count(word) for word in words}

    print("{}".format(compte))


def main():
    if len(sys.argv) == 2:
        listWords(sys.argv[1])
        sys.exit(0)
    else:
        sys.exit(1)

if __name__ == '__main__':
    main()