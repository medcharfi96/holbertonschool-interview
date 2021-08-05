#!/usr/bin/python3
"""
Pascal Triangle
"""


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers
    representing the Pascal’s triangle of n
    Arguments:
     - n will be always an integer
    Returns:
     An empty list if n <= 0
    """

    tab_F = []
    for i in range(0, n):
        tab = []
        for j in range(0, i + 1):
            if j == 0 or j == i:
                tab.append(1)
            else:
                sx = tab_F[i-1][j-1] + tab_F[i-1][j]
                tab.append(sx)
        tab_F.append(tab)
    return tab_F
