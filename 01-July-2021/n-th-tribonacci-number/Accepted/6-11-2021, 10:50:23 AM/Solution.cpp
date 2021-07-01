// https://leetcode.com/problems/n-th-tribonacci-number

class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) return n == 0 ? 0 : 1;
        int a = 0, b = 1, c = 1;
        for (int i = 3; i < n + 1; i++) {
            int cc = a + b + c;
            a = b; b = c; c = cc;
        } 
        return c;
    }
};