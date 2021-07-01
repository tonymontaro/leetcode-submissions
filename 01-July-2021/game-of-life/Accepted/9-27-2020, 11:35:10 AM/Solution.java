// https://leetcode.com/problems/game-of-life

class Solution {
    int[][] board;
    int rowlen;
    int colen;
    int[][] adjacentGridsAll = new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    public void gameOfLife(int[][] board) {
        // O(n) time | O(1) space
        if (board.length < 1) return;
        this.board = board;
        rowlen = board.length;
        colen = board[0].length;

        for (int r = 0; r < rowlen; r++) {
            for (int c = 0; c < colen; c++) {
                int adjacentAlive = 0;
                for (int[] ad : adjacentGridsAll) {
                    int row = r + ad[0];
                    int col = c + ad[1];
                    adjacentAlive += isInArea(row, col);
                }
                int val = board[r][c];
                if (val == 0 && adjacentAlive == 3) board[r][c] = 3;
                else if (val == 1 && (adjacentAlive < 2 || adjacentAlive > 3))
                    board[r][c] = 4;
            }
        }
        for (int r = 0; r < rowlen; r++) {
            for (int c = 0; c < colen; c++) {
                int val = board[r][c];
                if (val == 3) board[r][c] = 1;
                else if (val == 4) board[r][c] = 0;
            }
        }
    }
    int isInArea(int r, int c){
        if(r<0) return 0;
        if(c<0) return 0;
        if(r>=rowlen) return 0;
        if(c>=colen) return 0;
        return (board[r][c] == 1 || board[r][c] == 4) ? 1 : 0;
    }

}