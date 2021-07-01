// https://leetcode.com/problems/132-pattern

class Solution {
    public boolean find132pattern(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = Math.min(nums[i], dp[i - 1]);
        }
        TreeSet<Integer> right = new TreeSet<>();
        for (int i = n - 1; i > 0; i--) {
            int minNum = dp[i - 1];
            Integer minRight = right.higher(minNum);
            if (minRight != null && nums[i] > minNum && nums[i] > minRight)
                return true;
            right.add(nums[i]);
        }
        return false;
    }
}