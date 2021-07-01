// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> seen;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end() && i - seen[nums[i]] <= k) return true;
            seen[nums[i]] = i;
        } 

        return false;
    }
};