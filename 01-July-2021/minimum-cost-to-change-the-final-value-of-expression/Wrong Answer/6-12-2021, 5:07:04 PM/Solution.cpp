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
                brackets[st.top()] = i;
                st.pop();
            }
        }
        auto rs = solve(0, e.size() - 1, e);
        return rs[1];
    }
    v<int> solve(int l, int r, string& e) { // eval, flipCost, lastIdx
        v<int> left; int i = l; int flip;
        if (e[l] == '(') {
            left = solve(l + 1, brackets[l] - 1, e);
            i = brackets[l] + 1;
        } else {
            left = {e[i] - '0', 1, 0};
        }
//        print3(i, e[i], 0);

        while (i <= r) {
            if (e[i] == '0' || e[i] == '1') {
                i++; continue;
            }
            v<int> right;
            if (e[i + 1] == '(') right = solve(i + 2, brackets[i + 1] - 1, e);
            else right = {e[i + 1] - '0', 1, i + 2};
            int ans = 0;
            if (e[i] == '&') {
                ans = left[0] & right[0];
                flip = INT_MAX;
                if ((left[0] | right[0]) != ans) flip = 1;
                if (((left[0] ^ 1) & right[0]) != ans) flip = min(flip, left[1]);
                if ((left[0] & (right[0] ^ 1)) != ans) flip = min(flip, right[1]);
                if (((left[0] ^ 1) | right[0]) != ans) flip = min(flip, left[1] + 1);
                if ((left[0] | (right[0] ^ 1)) != ans) flip = min(flip, right[1] + 1);
                if (((left[0] ^ 1) | (right[0] ^ 1)) != ans) flip = min(flip, right[1]  + left[1] + 1);
            }
            if (e[i] == '|') {
                ans = left[0] | right[0];
                flip = INT_MAX;
                if ((left[0] & right[0]) != ans) flip = 1;
                if (((left[0] ^ 1) | right[0]) != ans) flip = min(flip, left[1]);
                if ((left[0] | (right[0] ^ 1)) != ans) flip = min(flip, right[1]);
                if (((left[0] ^ 1) & right[0]) != ans) flip = min(flip, left[1] + 1);
                if ((left[0] & (right[0] ^ 1)) != ans) flip = min(flip, right[1] + 1);
                if (((left[0] ^ 1) & (right[0] ^ 1)) != ans) flip = min(flip, right[1]  + left[1] + 1);
            }
            left = {ans, flip, 0};
            i = right[2];
        }
//        cout << l << " " << r << ' ' << left[0] << " " << left[1] << ' ' << i << endl;
        return {left[0], left[1], i};
    }
};