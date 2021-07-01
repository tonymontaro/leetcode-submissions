// https://leetcode.com/problems/count-primes

class Solution {
public:
    int countPrimes(int n) {
        int sieve[5000001] = {0};
        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (sieve[i] != 0) continue;
            ans++;
            for (int j = i + i; j < n; j += i) sieve[j] = 1;
        }
        return ans;
    }
};