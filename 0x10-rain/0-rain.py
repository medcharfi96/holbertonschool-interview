#!/usr/bin/python3
""" task 0 """


def water(arr, n):
    """
    Recursive function to help calculate how much water will be retained
    Arguments:
     - arr list of non-negative integers representing walls of width 1
     - n length of the list
    Returns:
     max_w How much water will be retained
    """
    max_w = 0

    for i in range(1, n - 1):
        # First find the max element in the left
        left = arr[i]
        for j in range(i):
            left = max(left, arr[j])

        # Then find the max element in the right
        right = arr[i]
        for j in range(i + 1, n):
            right = max(right, arr[j])

        # Save the max water
        max_w = max_w + (min(left, right) - arr[i])

    return max_w


def rain(walls):
    """
    calcule de eau
    :param walls:
    """
    if len(walls) < 2:
        return 0

    max_wtr = 0
    for fr in range(1, len(walls) - 1):
        left = walls[fr]
        for j in range(fr):
            left = max(left, walls[j])

        right = walls[fr]
        for j in range(fr + 1, len(walls)):
            right = max(right, walls[j])
        mini = min(left, right) - walls[fr]
        max_wtr = max_wtr + mini

    return max_wtr
