// https://leetcode.com/problems/subarray-sum-equals-k

import java.util.HashMap;

class Solution {
    public int subarraySum(int[] nums, int k) {
        // O(n) time and space
        int res = 0;
        HashMap<Integer, Integer> seenSum = new HashMap<>();
        seenSum.put(0, 1);
        int cummulative = 0;
        for (int num: nums) {
            cummulative += num;
            if (seenSum.containsKey(cummulative - k)) res += seenSum.get(cummulative - k);
            seenSum.merge(cummulative, 1, Integer::sum);
        }
        return res;
    }
}