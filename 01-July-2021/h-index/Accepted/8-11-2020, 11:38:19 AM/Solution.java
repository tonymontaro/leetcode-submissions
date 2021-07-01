// https://leetcode.com/problems/h-index

class Solution {
    public static int hIndex(int[] citations) {
        int n = citations.length;
        if (n == 0) return 0;
        int ans = 0;
        HashMap<Integer, Integer> count = counts(n, citations);
        int lessThan = 0;
        for (int i = 0; i < n + 1; i++) {
            if ((n - lessThan) < i) break;
            ans = i;
            lessThan += count.getOrDefault(i, 0);
        }
        return ans;
    }
    static HashMap<Integer, Integer> counts(int mx, int[] arr) {
        HashMap<Integer, Integer> counts = new HashMap<>();
        for (int value : arr) counts.merge(Math.min(value, mx), 1, Integer::sum);
        return counts;
    }
}