// https://leetcode.com/problems/divide-two-integers

class Solution {
    public int divide(int dividend, int divisor) {
        return (int)div(dividend, divisor);
    }

    long div(long dividend, long divisor) {
        long signa = dividend < 0 ? 0 : 1;
        long signb = divisor < 0 ? 0 : 1;
        long sign = signa ^ signb;
        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);

        long tmp = 0;
        long quo = 0;
        for (int i = 31; i >= 0; i--) {
            if (tmp + (divisor << i) <= dividend) {
                tmp += (divisor << i);
                quo = quo | (1l << i);
            }
        }
        return quo * (sign == 1 ? -1: 1);
    }
}