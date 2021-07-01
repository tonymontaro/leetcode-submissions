// https://leetcode.com/problems/non-decreasing-array

class Solution {
    public boolean checkPossibility(int[] nums) {
        if (nums.length <= 2) return true;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i]) {
                nums[i - 1] = nums[i];
                break;
            }
        }
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i]) return false;
        } 
        return true;
    }
}