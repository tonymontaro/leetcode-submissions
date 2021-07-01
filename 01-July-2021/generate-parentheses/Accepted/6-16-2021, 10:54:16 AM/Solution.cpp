// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string s;
        solve(n, 0, s);
        return ans;
    }
    void solve(int n, int open, string& s) {
        if (n == 0 && open == 0) {
            ans.push_back(s);
            return;
        }
        if (n > 0) {
            s += "(";
            solve(n - 1, open + 1, s);
            s.pop_back();
        }
        if (open > 0) {
            s += ")";
            solve(n, open - 1, s);
            s.pop_back();
        }
    }
};
