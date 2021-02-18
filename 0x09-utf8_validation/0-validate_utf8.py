#!/usr/bin/python3
""" task 0"""


def validUTF8(data):
    """
    :type data: List[int]
    :rtype: bool
    """
    nbr_b = 0
    for count in data:
        mask = 1 << 7
        if nbr_b == 0:
            while mask & count:
                nbr_b = nbr_b + 1
                mask = mask >> 1
            if nbr_b == 1 or nbr_b > 4:
                return False
            if nbr_b == 0:
                continue
        else:
            if (count >> 6) != 0b10:
                return False
        nbr_b = nbr_b - 1
    if nbr_b == 0:
        return True
    return False
