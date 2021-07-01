// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        int ans = 0;
        for (int i = left; i < right + 1; i++) {
            int num = i, cnt = 0;
            while (num > 0) {
                cnt += (num & 1);
                num >>= 1;
            }
            if (primes.find(cnt) != primes.end()) ans++;
        } 
        return ans;
    }
};