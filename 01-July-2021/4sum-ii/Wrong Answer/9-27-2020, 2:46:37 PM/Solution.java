// https://leetcode.com/problems/4sum-ii

class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        HashMap<Integer, Integer> count = new HashMap<>();
        for (int a : A) {
            for (int b : B)
                count.merge(a + b, 1, Integer::sum);
        }

        int ans = 0;
        for (int c : C) {
            for (int d : D) {
                int num = c + d;
                if (count.getOrDefault(-num, 0) > 0) {
                    ans++;
                    count.merge(-num, -1, Integer::sum);
                }
            }
        }
        return ans;
    }

}