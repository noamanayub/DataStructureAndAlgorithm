public class NQueens {
    private static boolean solveNQueens(int[][] board, int col, int n) {
        if (col >= n) {
            printBoard(board, n);
            return true;
        }

        boolean res = false;
        for (int i = 0; i < n; i++) {
            if (isSafe(board, i, col, n)) {
                board[i][col] = 1;
                res = solveNQueens(board, col + 1, n) || res;
                board[i][col] = 0; // Backtrack
            }
        }
        return res;
    }

    private static boolean isSafe(int[][] board, int row, int col, int n) {
        for (int i = 0; i < col; i++)
            if (board[row][i] == 1)
                return false;

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;

        for (int i = row, j = col; i < n && j >= 0; i++, j--)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    private static void printBoard(int[][] board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(board[i][j] == 1 ? "Q " : ". ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int n = 4;
        int[][] board = new int[n][n];
        solveNQueens(board, 0, n);
    }
}
