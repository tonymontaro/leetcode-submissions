// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.reserve(nums.size() + 1);
        prefix.push_back(0);
        for (int i = 0; i < nums.size(); i++) prefix.push_back(prefix[i] + nums[i]);
    }

    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};