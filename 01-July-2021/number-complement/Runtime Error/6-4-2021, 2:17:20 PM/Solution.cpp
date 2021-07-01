// https://leetcode.com/problems/number-complement

class Solution {
public:
    int findComplement(int num) {
        int size = 0; int nn = num;
        while (nn > 0) {
            size++;
            nn >>= 1;
        }
        int ones = (1 << size) - 1;
        return num ^ ones;
    }
};