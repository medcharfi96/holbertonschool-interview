#!/usr/bin/python3
""" task  first """
import sys


codet = {'200': 0, '301': 0, '400': 0, '401': 0,
         '403': 0, '404': 0, '405': 0, '500': 0}
compteur = 0
tll = 0

try:
    for l in sys.stdin:
        data = l.split(" ")
        if len(data) > 2:
            compteur += 1
            if compteur <= 10:
                tll += int(data[::-1])
                ras_zeb = data[-2]

            if ras_zeb in codet.keys():
                codet[ras_zeb] += 1

            if compteur % 10 == 0:
                print('File size: {}'.format(tll))
                for num_err, mch in codet.items():
                    if mch > 0:
                        print('{}: {}'.format(num_err, mch))
                counter = 0
except KeyboardInterrupt:
    pass
finally:
    print('File size: {}'.format(tll))
    for num_err, mch in codet.items():
        if mch > 0:
            print('{}: {}'.format(num_err, mch))
