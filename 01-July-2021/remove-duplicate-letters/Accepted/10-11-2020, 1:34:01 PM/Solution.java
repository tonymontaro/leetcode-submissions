// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
    public String removeDuplicateLetters(String s) {
        HashMap<Character, Integer> cnt = counts(s);
        Stack<Character> stack = new Stack<>();
        HashSet<Character> selected = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            cnt.merge(ch, -1, Integer::sum);
            if (selected.contains(ch)) continue;
            while (!stack.isEmpty() && ch < stack.peek() && cnt.get(stack.peek()) > 0) {
                char c = stack.pop();
                selected.remove(c);
            }
            stack.add(ch);
            selected.add(ch);
        }
//        out.println(stack);
        StringBuilder rs = new StringBuilder();
        for (char ch : stack) {
            rs.append(ch);
        }
        return rs.toString();
    }
    static HashMap<Character, Integer> counts(String word) {
        HashMap<Character, Integer> counts = new HashMap<>();
        for (int i = 0; i < word.length(); i++) counts.merge(word.charAt(i), 1, Integer::sum);
        return counts;
    }
}