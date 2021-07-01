// https://leetcode.com/problems/confusing-number

class Solution {
public:
    bool confusingNumber(int n) {
        bool containsSixOrNine = false;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            if (d == 6 || d == 9) containsSixOrNine = true;
            if ((d >= 2 && d <= 5) || d == 7) return false;
        }
        return containsSixOrNine;
    }
};