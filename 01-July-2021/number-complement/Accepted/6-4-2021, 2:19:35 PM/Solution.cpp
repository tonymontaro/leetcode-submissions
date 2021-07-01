// https://leetcode.com/problems/number-complement

#define ll long long

class Solution {
public:
    int findComplement(int num) {
        ll size = 0; ll nn = num;
        while (num > 0) {
            size++;
            num >>= 1;
        }
        ll ones = (1l << size) - 1;
        return nn ^ ones;
    }
};