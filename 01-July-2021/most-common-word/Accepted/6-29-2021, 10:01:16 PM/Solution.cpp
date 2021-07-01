// https://leetcode.com/problems/most-common-word

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& b) {
        set<string> banned;
        for (auto& s: b) banned.insert(s);
        string w = "";
        map<string, int> cnt;
        for (int i = 0; i < paragraph.size(); i++) {
            if (!isalpha(paragraph[i])) {
                if (!w.empty() && banned.find(w) == banned.end()) cnt[w]++;
                w = ""; continue;
            }
            w += tolower(paragraph[i]);
        }
        if (!w.empty() && banned.find(w) == banned.end()) cnt[w]++;
        string ans = "";
        for (auto& x: cnt) if (cnt[ans] < x.second) ans = x.first;
        return ans;
    }
};