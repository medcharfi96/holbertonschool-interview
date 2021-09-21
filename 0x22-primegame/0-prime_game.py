#!/usr/bin/python3
""" task"""


def delete_numbers(n, nums):
    """
    supprimer le nombre de la liste
    """
    for i in range(len(nums)):
        if nums[i] % n == 0:
            nums[i] = 0


def isWinner(x, nums):
    """
    main program
    """

    if not nums or x < 1:
        return None

    nums.sort()
    gagnant = False
    M = 0
    B = 0
    for jeu in range(x):
        nums2 = list(range(1, nums[jeu] + 1))
        turn = 0

        while True:
            change = False
            for i, n in enumerate(nums2):
                verif = True
                for i in range(2, n):
                    if n % i == 0:
                        verif = False
                if n > 1 and verif is True:
                    delete_numbers(n, nums2)
                    change = True
                    turn += 1
                    break

            if change is False:
                break

        if turn % 2 != 0:
            M += 1
        else:
            B += 1
    if M == B:
        return None
    if M > B:
        return "Maria"
    return "Ben"
