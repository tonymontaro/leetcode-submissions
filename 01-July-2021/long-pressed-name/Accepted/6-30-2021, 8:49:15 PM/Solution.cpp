// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto a = count(name);
        auto b = count(typed);
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i].first != b[i].first || a[i].second > b[i].second) return false;
        }
        return true;
    }
    vector<pair<char, int>> count(string& s) {
        vector<pair<char, int>> ans;
        char prev = s[0];
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != prev) {
                ans.push_back({s[i], cnt});
                cnt = 0;
            }
            prev = s[i];
            cnt++;
            if (i == s.size() - 1) ans.push_back({s[i], cnt});
        }
        return ans;
    }
};