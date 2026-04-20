#!/usr/bin/python3
"""
Return the fewest number of operations needed to result in exactly n H char.

You can only use two operations: Copy All and Paste.
Start with a single 'H'.
"""


def minOperations(n):
    """
    Calculate the fewest number of operations needed to get n H characters.

    Args:
        n (int): The desired number of H characters.

    Returns:
        int: The minimum number of operations, or 0 if impossible.
    """
    dv = 2  # diviseur
    f = []  # stocke les facteurs premiers

    if n <= 1:  # Si inférieur ou égal à 1 0 opération à faire
        return 0

    # Récupère les facteurs premiers --------- #
    while n > 1:  # Tant que n est inférieur n'a pas été réduit à 1
        # Tant que le diviseur courant divise n
        while n % dv == 0:
            f.append(dv)  # Ajoute le dv à la liste des facteurs
            n //= dv  # divise n par le facteur
        dv += 1  # passe au div suivant
    # ---------------------------------------- #

    return sum(f)  # retourne la somme des facteurs premiers
