#!/usr/bin/python3
""" task 0 """


def pascal_triangle(n):
    """
    pascale triangle algoritheme
    :param n: nbr de pas
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
