// https://leetcode.com/problems/minimum-cost-to-change-the-final-value-of-expression

#define umap unordered_map
#define uset unordered_set

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class Solution {
public:
    map<int, int> brackets;
    int minOperationsToFlip(string e) {
        stack<int> st;
        for (int i = 0; i < e.size(); i++) {
            if (e[i] == '(') st.push(i);
            if (e[i] == ')') {
                brackets[i] = st.top();
                st.pop();
            }
        }
        auto rs = solve(0, e.size() - 1, e);
        return rs[1];
    }
    v<int> solve(int l, int r, string& e) { // eval, flipCost
        if (l == r) return {e[l] - '0', 1};
        int start = brackets.find(r) != brackets.end() ? brackets[r] : r;
        if (l == start) return solve(l + 1, r - 1, e);
        int mid = start - 1;
        auto left = solve(l, mid - 1, e);
        auto right = solve(mid + 1, r, e);
        int lNum = left[0], lCost = left[1];
        int rNum = right[0], rCost = right[1];
        int val = e[mid] == '|' ? (lNum | rNum) : (lNum & rNum);
        if ((lNum ^ rNum) == 1) return {val, 1};
        int minCost = min(lCost, rCost);
        if (e[mid] == '&') {
            return {val, (lNum == 1) ? minCost : 1 + minCost};
        } else {
            return {val, (lNum == 0) ? minCost : 1 + minCost};
        }
    }
};
