// https://leetcode.com/problems/transform-to-chessboard

#define v vector

class Solution {
public:
    
    int n;
    int movesToChessboard(vector<vector<int>>& board) {
        n = board.size();
        map<string, int> mp;
        for (int r = 0; r < n; r++) {
            string s = "";
            for (int c = 0; c < n; c++) {
                s += (board[r][c] + '0');
            }
            mp[s]++;
        }
        if (mp.size() != 2) return -1;
        v<int> cnts;
        for (auto x: mp) {
            cnts.push_back(x.second);
            int zeros = 0;
            string s = x.first;
            for (int i = 0; i < s.size(); i++) if (s[i] == '0') zeros++;
            int ones = s.size() - zeros;
            if (abs(zeros - ones) > 1) return -1;
        }
        if (abs(cnts[0] - cnts[1]) > 1) return -1;
        return min(count(0, board), count(1, board));
    }
    int count(int val, v<v<int>> &board) {
        int other = (val + 1) % 2;
        int cnt = 0;
        for (int c = 0; c < n; c++) {
            if (c % 2 == 0 && board[0][c] != val) cnt++;
            if (c % 2 == 1 && board[0][c] != other) cnt++;
        }
        for (int r = 0; r < n; r++) {
            if (r % 2 == 0 && board[r][0] != val) cnt++;
            if (r % 2 == 1 && board[r][0] != other) cnt++;
        }
        return (cnt + 1) / 2;
    }
};