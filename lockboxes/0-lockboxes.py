#!/usr/bin/python3

"""
This function determines whether all boxes can be unlocked.

Each box may contain keys to other boxes.
- The input `boxes` is a list where each index represents a box,
  and the value is a list of keys inside that box.
- You start with box 0 unlocked.
- A key is represented by the index of the box it can open.
- The function uses Depth-First Search (DFS) with a stack to
  explore all accessible boxes.
- It returns True if all boxes can be visited/unlocked,
  otherwise False.
"""


def canUnlockAll(boxes):
    n = len(boxes)
    visited = set()
    stack = [0]  # start with box 0

    while stack:
        current = stack.pop()
        if current not in visited:
            visited.add(current)
            for key in boxes[current]:
                if 0 <= key < n and key not in visited:
                    stack.append(key)

    return len(visited) == n
