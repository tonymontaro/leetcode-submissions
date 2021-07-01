// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int, int> seen;
        set<pair<int, int>> res;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (seen.find(val - k) != seen.end()) res.insert({val - k, val});
            if (seen.find(val + k) != seen.end()) res.insert({val, val + k});
            seen[val]++;
        }
        return res.size();
    }
};