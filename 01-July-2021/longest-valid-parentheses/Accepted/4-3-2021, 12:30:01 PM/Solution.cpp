// https://leetcode.com/problems/longest-valid-parentheses

#define pi pair<int, int>
#define v vector


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        v<pi> found;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else {
                if (st.empty()) continue;
                found.push_back({st.top(), i + 1});
                st.pop();
            }
        }
        sort(found.begin(), found.end());

        int idx = 0, n = found.size();
        while (idx < n) {
            int a = found[idx].first, b = found[idx].second;
            idx++;
            while (idx < n && b >= found[idx].first) {
                b = max(b, found[idx].second);
                idx++;
            }
            ans = max(ans, b - a);
        }

        return ans;
    }
};