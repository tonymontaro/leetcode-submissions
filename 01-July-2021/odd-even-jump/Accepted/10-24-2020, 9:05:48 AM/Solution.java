// https://leetcode.com/problems/odd-even-jump

class Solution {
    // O(nlogn) time | O(n) space
    public int oddEvenJumps(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][2];
        dp[n - 1] = new int[]{1, 1};
        int ans = 1;
        TreeMap<Integer, Integer> seen = new TreeMap<>();
        seen.put(arr[n - 1], n - 1);

        for (int i = n - 2; i >= 0; i--) {
            int num = arr[i];
            Integer higher = seen.ceilingKey(num);
            Integer lower = seen.floorKey(num);
//            out.pp(i, num, higher, lower);
            int high = higher == null ? 0 : dp[seen.get(higher)][1];
            int low = lower == null ? 0 : dp[seen.get(lower)][0];
            ans += high;
            dp[i] = new int[]{high, low};
            seen.put(num, i);
        }

        return ans;
    }
}