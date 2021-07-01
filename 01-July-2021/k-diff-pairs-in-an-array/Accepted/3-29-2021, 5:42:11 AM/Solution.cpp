// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int, int>> ans;
        set<int> seen;
        for (auto num: nums) {
            if (seen.find(num - k) != seen.end()) ans.insert({num - k, num});
            if (seen.find(num + k) != seen.end()) ans.insert({num, num + k});
            seen.insert(num);
        }
        return ans.size();
    }
};