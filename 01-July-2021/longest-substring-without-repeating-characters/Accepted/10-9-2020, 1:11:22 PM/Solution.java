// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int ans = 0;
        int left = 0;
        HashMap<Character, Integer> count = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            while (count.getOrDefault(ch, 0) > 0) count.merge(s.charAt(left++), -1, Integer::sum);
            count.merge(ch, 1, Integer::sum);
            ans = Math.max(ans, i - left + 1);
        }
        return ans;
    }
}