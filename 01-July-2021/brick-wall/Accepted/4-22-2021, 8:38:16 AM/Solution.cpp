// https://leetcode.com/problems/brick-wall

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> count;
        for (auto row: wall) {
            int sm = 0;
            for (int i = 0; i < row.size()-1; ++i) {
                sm += row[i];
                count[sm]++;
            }
        }
        int best = 0;
        for (auto [k, x]: count) {
            best = max(best, x);
        }
        return wall.size() - best;
    }
};