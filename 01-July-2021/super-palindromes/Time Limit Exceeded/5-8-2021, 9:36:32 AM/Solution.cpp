// https://leetcode.com/problems/super-palindromes

#define ll long long
#define v vector

class Solution {
public:
    ll MX = 1000000000;
    vector<ll> result = {1, 4, 9};
    Solution() {
        for (int i = 2; i < 11; i++) {
            string txt(i, '0');
            solve(0, 0, txt);
        }
    }
    void solve(int i, int num, string& txt) {
        int sz = txt.size(), hf = (txt.size() - 1) / 2;
        if (num * pow(10, sz-i) > MX) return;
        if (i > hf) {
            for (int j = i; j < sz; j++) {
                int other = sz - j - 1;
                txt[j] = txt[other];
                num = (num * 10) + (txt[j] - '0');
            }
            isSuperPalindrome(num);
            return;
        }
        int start = i == 0 ? 1 : 0;
        for (int j = start; j < 10; j++) {
            int nn = (num * 10) + j;
            txt[i] = '0' + j;
            solve(i + 1, nn, txt);
        }
    }
    bool isSuperPalindrome(ll num) {
        if (num > MX) return false;
        ll pw = num * num;
        string s = to_string(pw);
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        result.push_back(pw);
        return true;
    }
    int superpalindromesInRange(string left, string right) {
        ll l = stoll(left), r = stoll(right);
        int res = 0;
        for (auto x: result) if (x >= l && x <= r) res++;
        return res;
    }
};