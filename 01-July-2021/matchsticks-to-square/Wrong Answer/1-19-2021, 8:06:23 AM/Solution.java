// https://leetcode.com/problems/matchsticks-to-square

class Solution {
    public boolean makesquare(int[] nums) {
        int total = sum(nums);
        if (total % 4 != 0) return false;
        int quarter = total / 4;

        for (int i = 0; i < 3; i++) {
            boolean[] seen = new boolean[nums.length];
            if (!solve(0, quarter, nums, seen)) return false;
            List<Integer> remaining = new ArrayList<>();
            for (int j = 0; j < nums.length; j++) if (!seen[j]) remaining.add(nums[j]);
            int[] nNums = new int[remaining.size()];
            for (int j = 0; j < remaining.size(); j++) nNums[j] = remaining.get(j);
            nums = nNums;
        }

        return sum(nums) == quarter;
    }

    public boolean solve(int idx, int total, int[] nums, boolean[] seen) {
        int tt = 1 << nums.length;
        for (int i = 0; i < tt; i++) {
            int res = 0;
            for (int j = 0; j < nums.length; j++) {
                if (((1 << j) & i) != 0) res += nums[j];
            }
            if (res == total) {
                for (int j = 0; j < 32; j++) {
                    if (((1 << j) & i) != 0) seen[j] = true;
                }
                return true;
            }
        }
        return false;
    }
    private static int sum(int... ins){ int total = 0; for (int v : ins) { total += v; } return total; }
}