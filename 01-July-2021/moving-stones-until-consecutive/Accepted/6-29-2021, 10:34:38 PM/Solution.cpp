// https://leetcode.com/problems/moving-stones-until-consecutive

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> vec = {a, b, c};
        sort(vec.begin(), vec.end());
        int mn = (vec[1] - vec[0] <= 2 || vec[2] - vec[1] <= 2) ? 1 : 2;
        int mx = (vec[1] - vec[0] - 1) + (vec[2] - vec[1] - 1);
        if (mx) return {mn, mx};
        return {0, 0};
    }
};