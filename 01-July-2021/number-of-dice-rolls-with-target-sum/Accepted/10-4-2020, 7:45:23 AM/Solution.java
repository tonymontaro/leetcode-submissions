// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum

class Solution {
    private static int e97 = (int) 1e9 + 7;
    Integer[][] dp;

    public int numRollsToTarget(int d, int f, int target) {
        dp = new Integer[d + 1][target + 1];
        return solve(d, f, target);
    }

    public int solve(int d, int f, int target) {
        if (target == 0 && d == 0) return 1;
        if (d <= 0 || target <= 0) return 0;
        if (dp[d][target] == null) {
            int ans = 0;
            for (int i = 1; i < f + 1; i++) {
                ans = (ans + solve(d - 1, f, target - i)) % e97;
            }
            dp[d][target] = ans;
        }
        return dp[d][target];
    }
}