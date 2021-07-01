// https://leetcode.com/problems/happy-number

class Solution {
    public boolean isHappy(int n) {
        HashMap<Integer, Boolean> seen = new HashMap<>();
        while (true) {
            if (seen.containsKey(n)) return false;
            seen.put(n, true);
            int sum = 0;
            while (n != 0){
                sum += Math.pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
            if (n == 1) return true;
        }
    }
}