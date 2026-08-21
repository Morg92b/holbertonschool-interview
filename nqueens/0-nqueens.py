#!/usr/bin/python3
"""
N queens puzzle solver
"""
import sys


def is_safe(board, row, col):
    """
    Check if it's safe to place a queen at board[row] = col.
    Checks the column and both diagonals.
    """
    for i in range(row):
        # board[i] == col checks the same column
        # board[i] - i == col - row checks the major diagonal (\)
        # board[i] + i == col + row checks the minor diagonal (/)
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True


def solve_nqueens(n, row, board):
    """
    Recursively solve the N queens problem using backtracking.
    """
    # If all queens are placed, print the solution
    if row == n:
        print([[i, board[i]] for i in range(n)])
        return

    # Try placing a queen in all columns one by one for the current row
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(n, row + 1, board)


def main():
    """
    Main function to execute the program and handle arguments.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Initialize a board array to store the column index of queens for each row
    board = [-1] * n
    solve_nqueens(n, 0, board)


if __name__ == "__main__":
    main()
