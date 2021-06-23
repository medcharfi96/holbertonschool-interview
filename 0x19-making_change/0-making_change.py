#!/usr/bin/python3
""" task 0 """


def makeChange(coins, total):
    """"""
    if (total < 0 or type(total) is not int):
        return (-1)
    coin = []
    coin = coins
    coin.sort()
    coin.reverse()
    op = 0
    for j in coins:
        if int(total // j) > 0:
            op += int(total / j)
            total = total % j

    if total == 0:
        return op
    return -1
