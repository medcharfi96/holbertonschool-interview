#!/usr/bin/python3
""" task 0 """


def island_perimeter(grid):
    """
    description of the func
    """
    res = 0
    large = len(grid)
    for a in range(large):
        for b in range(len(grid[a])):
            if grid[a][b] == 1:
                if a == 0 or grid[a - 1][b] == 0:
                    res = res + 1
                if b == 0 or grid[a][b - 1] == 0:
                    res = res + 1
                if a == len(grid) - 1 or grid[a + 1][b] == 0:
                    res = res + 1
                if b == len(grid[a]) - 1 or grid[a][y + 1] == 0:
                    res = res + 1
    return (res)
