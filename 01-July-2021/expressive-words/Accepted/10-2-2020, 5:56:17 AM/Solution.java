// https://leetcode.com/problems/expressive-words

class Solution {
    public int expressiveWords(String S, String[] words) {
        int ans = 0;
        for (String word : words) {
           if (isStretchy(S, word)) ans++;
        }
        return ans;
    }

    boolean isStretchy(String seq, String word) {
        if (seq.length() == 0 || word.length() == 0) return false;
        int s = 0;
        int w = 0;
        while (s < seq.length() || w < word.length()) {
            if (s >= seq.length() || w >= word.length()) return false;
            char ch = word.charAt(w);
            int cntW = 0;
            while (w < word.length() && word.charAt(w) == ch) {
                cntW++;
                w++;
            }
            int cntS = 0;
            while (s < seq.length() && seq.charAt(s) == ch) {
                cntS++;
                s++;
            }
            if (cntW > cntS || (cntS < 3 && cntW != cntS)) return false;
        }
        return true;
    }
}