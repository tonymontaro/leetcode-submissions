// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
    Long[][] cache;
    int n;
    int m;
    long[] nums;
    long[] mult;
    public int maximumScore(int[] numss, int[] multipliers) {
        m = multipliers.length;
        n = numss.length;
        nums = new long[n];
        for (int i = 0; i < n; i++) nums[i] = numss[i];
        mult = new long[m];
        for (int i = 0; i < m; i++) mult[i] = multipliers[i];  
                
        cache = new Long[m][m];
        return (int) solve(0, n - 1);
    }
    
    
    public long solve(int l, int r) {
        int rr = n - r - 1;
        int idx = n - (r - l + 1);
        if (idx >= m) return 0;
        if (cache[l][rr] != null) {
            return cache[l][rr]; 
        }
        long left = mult[idx] * nums[l] + solve(l + 1, r);
        long right = mult[idx] * nums[r] + solve(l, r - 1);
        long ans = Math.max(left, right);
        cache[l][rr] = ans; 
        return ans;
    }
}