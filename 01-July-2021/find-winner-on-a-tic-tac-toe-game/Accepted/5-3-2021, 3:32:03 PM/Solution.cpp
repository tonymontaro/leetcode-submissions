// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int rows[3] = {0};
        int cols[3] = {0};
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < moves.size(); i++) {
            int incr = i % 2 == 0 ? 1 : -1;
            auto mv = moves[i];
            rows[mv[0]] += incr;
            cols[mv[1]] += incr;
            if (mv[0] == mv[1]) diag1 += incr;
            if (mv[0] + mv[1] == 2) diag2 += incr;
            int a = max(abs(rows[mv[0]]), abs(cols[mv[1]])), b = max(abs(diag1), abs(diag2));
            if (max(a, b) == 3) return i % 2 == 0 ? "A" : "B";
        }
        return moves.size() < 9 ? "Pending" : "Draw";
    }
};