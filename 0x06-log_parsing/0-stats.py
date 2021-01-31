#!/usr/bin/python3
""" des """
import sys


status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0}
compteur = 0
taille = 0

try:
    for ligne in sys.stdin:
        info = ligne.split()
        info = info[::-1]

        if len(info) > 2:
            compteur = compteur + 1
            if compteur <= 10:
                code = info[1]
                taille += int(info[0])
            if code in status_codes:
                status_codes[str(code)] = status_codes[str(code)] + 1

            if compteur % 10 == 0:
                print('File size: {}'.format(taille))
                for s in sorted(status_codes):
                    if status_codes[s] != 0:
                        print('{}: {}'.format(s, status_codes[s]))
                compteur = 0
finally:
    print('File size: {}'.format(taille))
    for s in sorted(status_codes):
        if status_codes[s] != 0:
            print('{}: {}'.format(s, status_codes[s]))
