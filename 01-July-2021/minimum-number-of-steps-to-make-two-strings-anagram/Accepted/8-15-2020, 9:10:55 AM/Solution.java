// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
    public static int minSteps(String s, String t) {
        HashMap<Character, Integer> sCount = counts(s);
        HashMap<Character, Integer> tCount = counts(t);
        int ans = 0;
        for (char sKey : sCount.keySet()) {
            ans += Math.max(0, sCount.get(sKey) - tCount.getOrDefault(sKey, 0));
        }
        return ans;
    }
    static HashMap<Character, Integer> counts(String word) {
        HashMap<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < word.length(); i++) counts.merge(word.charAt(i), 1, Integer::sum);
        return counts;
    }
}