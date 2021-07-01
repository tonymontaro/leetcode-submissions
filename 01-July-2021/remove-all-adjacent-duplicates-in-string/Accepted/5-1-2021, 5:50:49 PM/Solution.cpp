// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string S) {
        vector<char> st;
        for (int i =0; i < S.size(); ++i) {
            if (!st.empty() && st[st.size() - 1] == S[i]) {
                st.pop_back();
            } else {
                st.push_back(S[i]);
            }
        }
        string ans = "";
        for (auto x: st) ans += x;
        return ans;
    }
};