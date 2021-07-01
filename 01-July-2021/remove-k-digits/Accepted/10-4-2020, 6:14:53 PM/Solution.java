// https://leetcode.com/problems/remove-k-digits

class Solution {
    public String removeKdigits(String seq, int k) {
        int n = seq.length();
        if (k >= n) return "0";
        HashMap<Integer, Deque<Integer>> nums = new HashMap<>();
        for (int i = 0; i < 10; i++) nums.put(i, new ArrayDeque<>());
        for (int i = 0; i < n; i++) {
            int num = seq.charAt(i) - '0';
            nums.get(num).add(i);
        }
//        out.println(nums);
        int idx = 0;
        int toSelect = n - k;
        StringBuilder res = new StringBuilder();
        while (k > 0 && toSelect > 0) {
            for (int i = 0; i < 10; i++) {
                if (!nums.containsKey(i) || nums.get(i).isEmpty()) continue;
                Deque<Integer> deque = nums.get(i);
                while (!deque.isEmpty() && deque.peekFirst() < idx) deque.pollFirst();
                Integer id = deque.peekFirst();
                if (id == null || id - idx > k) continue;
                res.append(i);
                k -= id - idx;
                idx = id + 1;
                toSelect -= 1;
                break;
            }
        }
        if (toSelect > 0) res.append(seq.substring(idx));
        idx = 0;
        while (idx < res.length() && res.charAt(idx) == '0') idx++;
        int ln = res.substring(idx).length();
        return ln == 0 ? "0" : res.substring(idx);
    }
}