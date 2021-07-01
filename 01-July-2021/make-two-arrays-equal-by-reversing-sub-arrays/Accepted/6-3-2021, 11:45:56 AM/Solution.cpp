// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int nums[1001] = {0};
        for (auto& i: target) nums[i]++;
        for (auto& i: arr) nums[i]--;
        return all_of(nums, nums + 1001, [](int i){return i == 0;});
    }
};