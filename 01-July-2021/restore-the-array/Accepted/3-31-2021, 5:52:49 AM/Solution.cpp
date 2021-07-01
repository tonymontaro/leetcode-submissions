// https://leetcode.com/problems/restore-the-array

#define v vector
#define ll long long

ll cache[100000];

class Solution {
public:
    int n, k;
    ll mod = 1e9 + 7;
    int numberOfArrays(string s, int kk) {
        v<int> arr;
        n = s.size(), k = kk;
        for (int i = 0; i < s.size(); i++) {
            arr.push_back(s[i] - '0');
            cache[i] = -1;
        }
        return solve(0, arr);
    }
    ll solve(int idx, v<int> &arr) {
        if (idx >= n) return 1;
        if (arr[idx] == 0) return 0;
        if (cache[idx] != -1) return cache[idx];
        ll ans = 0;
        ll num = 0;
        for (int i = idx; i < n; i++) {
            num = (num * 10) + arr[i];
            if (num > k) break;
            ans = (ans + solve(i + 1, arr)) % mod;
        } 
        cache[idx] = ans;
        return ans;
    }
};