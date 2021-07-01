// https://leetcode.com/problems/sort-colors

class Solution {
    public void sortColors(int[] nums) {
        int l = 0;
        int r = nums.length - 1;
        int idx = 0;
        while (idx < nums.length && idx <= r) {
            int num = nums[idx];
            if (num == 0 && idx > l) {
                swap(nums, idx, l);
                l++;
            } else if (num == 2 && idx < r) {
                swap(nums, idx, r);
                r--;
            } else
                idx++;
        }
    }
        public static int[] swap(int[] arr, int left, int right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        return arr;
    }
}