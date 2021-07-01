// https://leetcode.com/problems/non-decreasing-array

class Solution {
    public boolean checkPossibility(int[] nums) {
        int n = nums.length;
        if (nums.length <= 2) return true;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i]) {
                if (i != n - 1 && nums[i - 1] > nums[i + 1])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                break;
            }
        }
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i]) return false;
        }
        return true;
    }
}