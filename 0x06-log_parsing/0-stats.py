#!/usr/bin/python3
""" des """
import sys


codet = {'200': 0, '301': 0, '400': 0, '401': 0,
         '403': 0, '404': 0, '405': 0, '500': 0}
tll = 0

try:
    for x, line in enumerate(sys.stdin, 1):
        s_l = line.split()
		s_l = s_l[::-1]
        if len(s_l) > 2:
            stat_c = s_l[0]
            tll += int(s_l[len(s_l) - 1])
            if stat_c in codet.keys():
                codet[stat_c] += 1
        if x == 10:
            print("File size: {}".format(tll))
            for k, val in sorted(codet):
                if val > 0:
                    print("{}: {}".format(k, val))
except KeyboardInterrupt:
    pass
finally:
    print('File size: {:d}'.format(tll))
    for k, val in sorted(codet.keys()):
        if val != 0:
            print("{}: {:d}".format(k, val))
