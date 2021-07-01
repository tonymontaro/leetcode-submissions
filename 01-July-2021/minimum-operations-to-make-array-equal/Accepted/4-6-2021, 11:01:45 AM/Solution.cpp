// https://leetcode.com/problems/minimum-operations-to-make-array-equal

class Solution {
public:
    int minOperations(int n) {
        if (n == 1) return 0;
        int half = n / 2;
        int sm = (half * (1 + getVal(half - 1))) / 2;
        int halfVal = getVal(half);
        if (n % 2 == 0) {
            halfVal = (halfVal + getVal(half - 1)) / 2;
        }
        return (halfVal * half) - sm;
    }
    int getVal(int num) {
        return (2 * num) + 1;
    }
};
