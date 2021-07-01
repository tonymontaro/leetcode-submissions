// https://leetcode.com/problems/buddy-strings

class Solution {
    public boolean buddyStrings(String a, String b) {
        if (a.length() != b.length()) return false;
        HashMap<Character, Integer> aCount = counts(a);
        HashMap<Character, Integer> bCount = counts(b);
        if (!aCount.equals(bCount)) return false;
        int diff = 0;
        for (int i = 0; i < a.length(); i++) if (a.charAt(i) != b.charAt(i)) diff++;
        if (diff == 2) return true;
        if (diff != 0) return false;
        for (int v: aCount.values()) if (v > 1) return true;
        return false;
    }
    static HashMap<Character, Integer> counts(String word) {
        HashMap<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < word.length(); i++) counts.merge(word.charAt(i), 1, Integer::sum);
        return counts;
    }
}