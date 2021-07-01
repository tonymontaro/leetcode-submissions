// https://leetcode.com/problems/climbing-stairs

import java.util.HashMap;

class Solution {
    HashMap<Integer, Integer> seen = new HashMap<>();
    public int climbStairs(int n) {
        if (n <= 2) return n;
        if (!seen.containsKey(n)) seen.put(n, climbStairs(n - 1) + climbStairs(n - 2));
        return seen.get(n);
    }
}