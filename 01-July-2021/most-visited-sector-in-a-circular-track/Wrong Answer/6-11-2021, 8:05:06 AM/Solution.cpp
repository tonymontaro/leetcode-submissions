// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        for (int i = rounds[0]; i < rounds[rounds.size() - 1] + 1; i++) ans.push_back(i);
        return ans;
    }
};