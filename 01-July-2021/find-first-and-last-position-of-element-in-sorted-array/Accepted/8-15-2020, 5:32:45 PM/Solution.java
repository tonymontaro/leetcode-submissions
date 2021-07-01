// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
    public static int[] searchRange(int[] nums, int target) {
        int lo = lowerBound(nums, target);
        int hi = lowerBound(nums, target + 1) - 1;
        if (lo <= hi) return new int[]{lo, hi};
        return new int[]{-1, -1};
    }

    public static int lowerBound(int[] array, long obj) {
        int l = 0, r = array.length - 1;
        while (r - l >= 0) {
            int c = (l + r) / 2;
            if (obj <= array[c]) {
                r = c - 1;
            } else {
                l = c + 1;
            }
        }
        return l;
    }
}