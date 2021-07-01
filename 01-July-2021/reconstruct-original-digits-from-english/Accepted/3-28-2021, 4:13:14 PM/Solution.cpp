// https://leetcode.com/problems/reconstruct-original-digits-from-english

#define v vector

class Solution {
public:
    string originalDigits(string s) {
        map<char, int> count;
        for (int i = 0; i < s.size(); i++) count[s[i]]++;
        map<int, int> res;
        v<pair<string, int>> arr = {
                {"two", 2},
                {"four", 4},
                {"six", 6},
                {"eight", 8},
                {"zero", 0},
                {"five", 5},
                {"three", 3},
                {"one", 1},
                {"nine", 9},
                {"seven", 7}
                };
        for (auto [st, num]: arr) {
            int mn = INT_MAX;
            for (int i = 0; i < st.size(); i++) mn = min(mn, count[st[i]]);
            for (int i = 0; i < st.size(); i++) count[st[i]] -= mn;
            res[num] += mn;
        }
        string ans = "";
        for (int i = 0; i < 10; i++) {
            string a(res[i], i + '0');
            ans += a;
        }
        return ans;
    }
};