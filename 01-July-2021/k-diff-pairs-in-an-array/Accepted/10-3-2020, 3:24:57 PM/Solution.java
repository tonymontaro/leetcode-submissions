// https://leetcode.com/problems/k-diff-pairs-in-an-array

class Solution {
    public int findPairs(int[] nums, int k) {
        HashSet<Integer> seen = new HashSet<>();
        HashSet<Integer> selected = new HashSet<>();

        int count = 0;
        for (int num : nums) {
            if (selected.contains(num)) continue;
            if (k == 0 && seen.contains(num)) {
                count++;
                selected.add(num);
                continue;
            }
            int diff = num - k;
            int sm = num + k;
            if (seen.contains(diff)) {
                selected.add(diff);
                selected.add(num);
                count++;
            }
            if (seen.contains(sm)) {
                selected.add(num);
                selected.add(sm);
                count++;
            }
            seen.add(num);
        }
        return count;
    }
}