// https://leetcode.com/problems/happy-number

class Solution {
    public boolean isHappy(int n) {
        HashMap<Integer, Boolean> seen = new HashMap<>();
        while (true) {
            if (seen.containsKey(n)) return false;
            seen.put(n, true);
            String num = String.valueOf(n);
            n = 0;
            for (int i = 0; i < num.length(); i++) {
                n += Math.pow(Integer.parseInt(num.substring(i, i+1)), 2);
            }
            if (n == 1) return true;
        }

    }
}