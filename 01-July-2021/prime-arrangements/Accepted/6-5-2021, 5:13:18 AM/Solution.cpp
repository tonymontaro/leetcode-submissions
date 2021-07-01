// https://leetcode.com/problems/prime-arrangements

#define ll long long

class Solution {
public:
    vector<int> primes;
    ll mod = 1e9 + 7;
    int numPrimeArrangements(int n) {
        int cnt = 0;
        int seen[101] = {0};
        for (int i = 2; i < n + 1; i++) {
            if (seen[i]) continue;
            cnt++;
            for (int j = i + i; j < 101; j += i) seen[j] = 1;
        }
        ll ans = (fac(cnt) * fac(n - cnt)) % mod;
        return ans;
    }
    ll fac(int n) {
        ll ans = 1;
        for (int i = 1; i < n + 1; i++) ans = (ans * i) % mod;
        return ans;
    }
};