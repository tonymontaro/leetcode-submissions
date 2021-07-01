// https://leetcode.com/problems/missing-number

class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            while (nums[i] < n && nums[i] != i) {
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        for (int i = 0; i < n + 1; i++) if (i != nums[i]) return i;
        return 0;
    }
}