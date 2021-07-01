// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
    public int findPairs(int[] nums, int k) {
        HashSet<Integer> seen = new HashSet<>();
        int count = 0;
        for (int num : nums) {
            if (seen.contains(num)) continue;
            int diff = num - k;
            int sm = num + k;
            if (seen.contains(diff)) {
                count++;
            }
            if (seen.contains(sm)) {
                count++;
            }
            seen.add(num);
        }
        return count;
    }
}