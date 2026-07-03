#!/usr/bin/python3
"""
Module for UTF-8 Validation
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.
    """
    num_bytes = 0

    mask1 = 1 << 7
    mask2 = 1 << 6

    for i in data:
        mask = 1 << 7
        if num_bytes == 0:
            while mask & i:
                num_bytes += 1
                mask = mask >> 1

            if num_bytes == 0:
                continue

            if num_bytes == 1 or num_bytes > 4:
                return False
        else:
            if not (i & mask1 and not (i & mask2)):
                return False

        num_bytes -= 1

    return num_bytes == 0
