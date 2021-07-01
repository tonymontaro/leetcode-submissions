// https://leetcode.com/problems/total-hamming-distance

class Solution {
    public int totalHammingDistance(int[] nums) {
        int[] counts = new int[31];
        int remove = 0;
        int total = 0;

        for (int num : nums) {
            int setBits = 0;
            for (int i = 0; i < 31; i++) {
                int mask = 1 << i;
                if ((mask & num) != 0) {
                    setBits += 1;
                    remove += counts[i] * 2;

                    counts[i] += 1;
                }
            }
            total += setBits * (nums.length - 1);
        }

        return total - remove;
    }
}