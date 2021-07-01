// https://leetcode.com/problems/h-index

class Solution {
    public static int hIndex(int[] citations) {
        int n = citations.length;
        if (n == 0) return 0;
        int ans = 0;
        Arrays.sort(citations);
        for (int i = n - 1; i >= 0; i--) {
            int idx = n - i;
            if (citations[i] < idx) break;
            ans = idx;
        }
        return ans;
    }
}