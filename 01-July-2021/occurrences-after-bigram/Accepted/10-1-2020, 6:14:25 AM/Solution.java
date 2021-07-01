// https://leetcode.com/problems/occurrences-after-bigram

class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        List<String> res = new ArrayList<>();
        String[] words = text.split(" ");
        int n = words.length;
        for (int i = 1; i < n; i++) {
            if (words[i].equals(second) && words[i - 1].equals(first)) {
                if (i + 1 < n) res.add(words[i + 1]);
            }
        }

        String[] finRes = new String[res.size()];
        for (int i = 0; i < res.size(); i++) finRes[i] = res.get(i);
        return finRes;
    }
}