// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string S) {
        string ans = "";
        for (int i=0; i < S.size(); ++i) {
            if (!ans.empty() && ans[ans.size() - 1] == S[i]) {
                ans.pop_back();
            } else {
                ans.push_back(S[i]);
            }
        }
        return ans;
    }
};