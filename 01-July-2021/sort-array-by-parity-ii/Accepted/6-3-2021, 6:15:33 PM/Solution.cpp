// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int even = 0, odd = 1, last = nums.size() - 1;
        while (!((even == last && nums[last] % 2 == 0) || (odd == last && nums[last] % 2 == 1))) {
            if (nums[last] % 2 == 0) {
                swap(nums[last], nums[even]);
                even += 2;
            } else {
                swap(nums[last], nums[odd]);
                odd += 2;
            }
        }
        return nums;
    }
};