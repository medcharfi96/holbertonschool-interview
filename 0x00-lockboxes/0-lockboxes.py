#!/usr/bin/python3
"""inter"""


def canUnlockAll(boxes):
    """ desc"""
    if isinstance(boxes, list):
        return False
    if len(boxes) == 0:
        return False
    elif boxes[0] == []:
        return 0

    cle = [0]
    while i in len(boxes):
        for j in boxes[k]:
            if j not in list and j < len(boxes.max()):
                cle.append(j)
    i += 1
    if len(cle) == len(boxes):
        return True
    return False
