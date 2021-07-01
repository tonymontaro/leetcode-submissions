// https://leetcode.com/problems/rank-transform-of-an-array

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> ranks;
        for (auto& x: arr) ranks[x] = 0;
        int i = 1;
        for (auto& x: ranks) x.second = i++;
        for (int& x: arr) x = ranks[x];
        return arr;
    }
};