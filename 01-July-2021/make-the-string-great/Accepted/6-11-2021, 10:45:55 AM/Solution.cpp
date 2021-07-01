// https://leetcode.com/problems/make-the-string-great

class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (auto x: s) {
            if (!ans.empty() && tolower(x) == tolower(ans[ans.size()-1]) && x != ans[ans.size()-1]) ans.pop_back();
            else ans.push_back(x);
        }
        return ans;
    }
};