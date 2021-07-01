// https://leetcode.com/problems/power-of-three

#define ll long long

class Solution {
public:
    unordered_set<int> powers;
    Solution() {
        ll i = 1;
        ll mx = 3e9;
        while (i < mx) {
            powers.insert(i);
            i *= 3;
        }
    }
    bool isPowerOfThree(int n) {
        return n > 0 && powers.find(n) != powers.end();
    }
};