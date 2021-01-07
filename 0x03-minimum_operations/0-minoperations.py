#!/usr/bin/python3
"""
fonction minOperation
"""


def minOperations(n):
    """
    description de la function
    :param n: nombre de répétition
    :return:
    """
    if not isinstance(n, int) or n <= 1:
        return 0
    counter = 0
    i = 2
    while (i <= n):
        if n % i == 0:
            counter = counter + i
            n = n / i
        else:
            i = i + 1
    return (counter)
