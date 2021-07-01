// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
    public int titleToNumber(String s) {
        int n = s.length();
        int ans = 0;
        int mult = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans += (mult * (s.charAt(i) - 'A' + 1));
            mult *= 26;
        }
        return ans;
    }
}