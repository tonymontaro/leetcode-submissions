// https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int r, int c, vector<vector<int>>& ops) {
        for (auto& x: ops) {
            r = min(r, x[0]);
            c = min(c, x[1]);
        }
        return r * c;
    }
};