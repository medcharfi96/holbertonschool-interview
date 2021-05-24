#!/usr/bin/python3
""" task 0"""


def rotate_2d_matrix(matrix):
    """
    rotate the column and row of the matrix
    :param matrix:
    """
    i = 0
    while i < len(matrix[0]):
        for j in range(i, len(matrix[0])):
            aux = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = aux
        i += 1
    for j in range(len(matrix[0])):
        matrix[j].reverse()
