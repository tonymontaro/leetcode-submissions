// https://leetcode.com/problems/longest-valid-parentheses

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;

        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (st.empty()) {
                    left = i + 1;
                    continue;
                }
                if (st.size() > 1)
                    left = st.top();
                ans = max(ans, i - left + 1);
                st.pop();
            }
        }

        return ans;
    }
};