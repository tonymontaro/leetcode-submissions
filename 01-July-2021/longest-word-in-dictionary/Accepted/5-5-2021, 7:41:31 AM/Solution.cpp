// https://leetcode.com/problems/longest-word-in-dictionary

bool compare(string &a, string &b) {
    if (a.size() < b.size()) return true;
    if (b.size() < a.size()) return false;
    return a < b;
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        set<string> seen;
        string ans = "";
        for (auto &w: words) {
            if (w.size() > 1 && seen.find(w.substr(0, w.size() - 1)) == seen.end()) continue;
            seen.insert(w);
            if (w.size() > ans.size()) ans = w;
        }
        return ans;
    }
};