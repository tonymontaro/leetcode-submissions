// https://leetcode.com/problems/sum-of-two-integers

class Solution {
    public int getSum(int a, int b) {
        int next = a & b;
        int total = a ^ b;
        next <<= 1;
        while (next != 0) {
            int next2 = (next & total);
            next2 <<= 1;
            total = next ^ total;
            next = next2;
        }
        return total;
    }
}