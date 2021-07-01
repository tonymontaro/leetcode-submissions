// https://leetcode.com/problems/count-submatrices-with-all-ones

class Solution {
    int rowlen;
    int colen;
    int[][] grid;
    int ans = 0;
    public int numSubmat(int[][] mat) {
        if (mat.length <= 0 || mat[0].length <= 0) return 0;
        rowlen = mat.length;
        colen = mat[0].length;
        grid = mat;
        ans = 0;
        for (int i = 0; i < rowlen; i++) {
            for (int c = 0; c < colen; c++)
                calc(i, c);
        }
        return ans;
    }


    void calc(int r, int c) {
        if (grid[r][c] == 0) return;
        int orig = ans;
        int oC = c;
        ans++;
        count(r + 1, c, 0);
        int moveBack = 1;
        c += 1;
        while (c < colen && grid[r][c] == 1) {
            ans++;
            count(r + 1, c++, moveBack++);
        }
//        out.pp(r, oC, ans - orig);
    }
    
    void count(int r, int c, int moveBack) {
        if (r >= rowlen || grid[r][c] == 0) return;
        int move = moveBack;
        if (moveBack == 0) {
            ans++;
            count(r + 1, c, moveBack);
            return;
        }
        int cc = c - 1;
        while (move > 0) {
            if (grid[r][cc] == 0) return;
            cc--;
            move--;
        }
        ans++;
        count(r + 1, c, moveBack);
    }
}