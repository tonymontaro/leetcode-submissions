// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer

class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1, s = 0;
        while (n > 0) {
            p *= n % 10;
            s += n % 10;
            n /= 10;
        }
        return p - s;
    }
};