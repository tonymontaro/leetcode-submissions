// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n

class Solution {
    public boolean queryString(String seq, int n) {
        int MAX = 1_000_000;
        if (n > MAX) return false;
        HashSet<Integer> nums = new HashSet<>();
        int sz = seq.length();
        for (int i = 0; i < sz; i++) {
            char ch = seq.charAt(i);
            if (ch == '0') continue;
            int num = 0;
            for (int j = i; j < sz; j++) {
                num += (seq.charAt(j) - '0');
                nums.add(num);
                num <<= 1;
            }
        }
        for (int i = 1; i < n + 1; i++) if (!nums.contains(i)) return false;
        return true;
    }
}