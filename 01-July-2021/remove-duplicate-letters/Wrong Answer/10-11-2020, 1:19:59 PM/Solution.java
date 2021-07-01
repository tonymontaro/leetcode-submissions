// https://leetcode.com/problems/remove-duplicate-letters

class Solution {
    public String removeDuplicateLetters(String s) {
        HashMap<Character, Integer> cnt = counts(s);
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            while (!stack.isEmpty() && ch < stack.peek() && cnt.get(stack.peek()) > 1) stack.pop();
            stack.add(ch);
        }
//        out.println(stack);
        StringBuilder rs = new StringBuilder();
        HashSet<Character> selected = new HashSet<>();
        for (char ch : stack) {
            if (selected.contains(ch)) continue;
            selected.add(ch);
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