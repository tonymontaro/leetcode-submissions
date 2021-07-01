// https://leetcode.com/problems/confusing-number

class Solution {
public:
    bool confusingNumber(int n) {
        int oldn = n, res = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            if ((d >= 2 && d <= 5) || d == 7) return false;
            res *= 10;
            if (d == 6) res += 9;
            else if (d == 9) res += 6;
            else res += d;
        }
        return oldn != res;
    }
};