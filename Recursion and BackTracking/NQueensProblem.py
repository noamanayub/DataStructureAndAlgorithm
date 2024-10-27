def solve_n_queens(board, col, n):
    if col >= n:  # All queens are placed
        print_board(board, n)
        return True

    res = False
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            res = solve_n_queens(board, col + 1, n) or res
            board[i][col] = 0  # Backtrack
    return res

def is_safe(board, row, col, n):
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, n, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True

def print_board(board, n):
    for row in board:
        print(" ".join("Q" if x else "." for x in row))
    print()

n = 4
board = [[0] * n for _ in range(n)]
solve_n_queens(board, 0, n)
