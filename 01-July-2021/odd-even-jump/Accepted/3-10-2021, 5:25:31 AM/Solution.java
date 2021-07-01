// https://leetcode.com/problems/odd-even-jump

class Solution {
    public int oddEvenJumps(int[] arr) {
        TreeMap<Integer, int[]> mp = new TreeMap<>();
        int n = arr.length;
        int ans = 1;
        mp.put(arr[n - 1], new int[]{1, 1});
        for (int i = n - 2; i >= 0; i--) {
            int num = arr[i];
            Integer higher = mp.ceilingKey(num);
            int h = (higher != null && mp.get(higher)[1] == 1) ? 1 : 0;
            Integer lower = mp.floorKey(num);
            int l = (lower != null && mp.get(lower)[0] == 1) ? 1 : 0;

            ans += h == 1 ? 1 : 0;
            mp.put(num, new int[]{h, l});
        }
        return ans;
    }
}