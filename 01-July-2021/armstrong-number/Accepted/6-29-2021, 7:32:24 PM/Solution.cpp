// https://leetcode.com/problems/armstrong-number

#define ll long long

class Solution {
public:
    bool isArmstrong(int n) {
        int oldn = n;
        int ln = to_string(n).size();
        ll res = 0;
        while (n > 0) {
            res += pow(n % 10, ln);
            n /= 10;
        }
        return res == oldn;
    }
};
