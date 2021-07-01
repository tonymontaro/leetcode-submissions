// https://leetcode.com/problems/expressive-words

class Solution {
    public int expressiveWords(String S, String[] words) {
        HashMap<Character, Integer> count = counts(S);
        int ans = 0;
        for (String word : words) {
            if (isStretchy(count, counts(word))) ans++;
        }
        return ans;
    }

    boolean isStretchy(HashMap<Character, Integer> count, HashMap<Character, Integer> wCount) {
        if (count.size() != wCount.size()) return false;
        for (char ch : count.keySet()) {
            int cnt = count.get(ch);
            if (cnt >= 3) cnt = 1;
            if (wCount.getOrDefault(ch, 0) != cnt) return false;
        }
        return true;
    }
    static HashMap<Character, Integer> counts(String word) {
        HashMap<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < word.length(); i++) counts.merge(word.charAt(i), 1, Integer::sum);
        return counts;
    }
}