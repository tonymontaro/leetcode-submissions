// https://leetcode.com/problems/smallest-integer-divisible-by-k

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector

int seen[100000];
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int ln = 1;
        ll num = 1;
        ll mod = k;
        memset(seen, 0, sizeof(seen));
        while (num % k != 0) {
            num = (num * 10  + 1) % mod;
            ln++;
            if (seen[num] == 1) return -1;
            seen[num] = 1;
        }
        return ln;
    }
};