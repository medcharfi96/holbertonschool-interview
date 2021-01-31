#!/usr/bin/python3
""" des """
import sys


codet = {'200': 0, '301': 0, '400': 0, '401': 0,
         '403': 0, '404': 0, '405': 0, '500': 0}
compteur = 0
tll = 0

try:
    for l in enumerate(sys.stdin, 1):
        data = l.split()
        if len(data) > 2:
            compteur += 1
            if compteur <= 10:
                tll += int(data[0])
                ras_zeb = data[1]
            if ras_zeb in codet.keys():
                codet[ras_zeb] += 1
            if compteur % 10 == 0:
                print('File size: {}'.format(tll))
                for num_err, mch in sorted(codet.items()):
                    if mch > 0:
                        print('{}: {}'.format(num_err, mch))
                counter = 0
except KeyboardInterrupt:
    pass
finally:
    print('File size: {}'.format(tll))
    for num_err, mch in sorted(codet.items()):
        if mch > 0:
            print('{}: {}'.format(num_err, mch))
