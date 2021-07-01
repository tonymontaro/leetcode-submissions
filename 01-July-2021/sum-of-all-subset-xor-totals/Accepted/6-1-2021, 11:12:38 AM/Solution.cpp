// https://leetcode.com/problems/sum-of-all-subset-xor-totals

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int setBits = 0;
        for (auto& num: nums) setBits |= num;
        return setBits * (1 << (nums.size() - 1));
    }
};