// https://leetcode.com/problems/most-visited-sector-in-a-circular-track

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int first = rounds[0], last = rounds[rounds.size() - 1];
        if (last >= first) {
            for (int i = rounds[0]; i < rounds[rounds.size() - 1] + 1; i++) ans.push_back(i);
        } else {
            for (int i = 1; i < last + 1; i++) ans.push_back(i);
            for (int i = first; i < n + 1; i++) ans.push_back(i);
        }

        return ans;
    }
};