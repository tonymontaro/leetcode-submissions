// https://leetcode.com/problems/binary-prefix-divisible-by-5

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int num = 0;
        vector<bool> ans;
        ans.reserve(nums.size());
        for (auto x: nums) {
            num = (num << 1) | x;
            ans.push_back(num % 5 == 0);
            num = num % 5;
        }
        return ans;
    }
};