// https://leetcode.com/problems/candy

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long


class Solution {
public:
    int candy(vector<int>& ratings) {
        queue<int> q;
        v<int> ans(ratings.size());
        int n = ratings.size();
        for (int i = 0; i < n; i++) {
            if ((i == 0 || ratings[i] <= ratings[i-1]) && (i == n-1 || ratings[i] <= ratings[i+1])) {
                q.push(i);
                ans[i] = 1;
            }
        }

        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            if (idx > 0 && ratings[idx] > ratings[idx-1]) ans[idx] = max(ans[idx], 1 + ans[idx - 1]);
            if (idx < n - 1 && ratings[idx] > ratings[idx+1]) ans[idx] = max(ans[idx], 1 + ans[idx + 1]);
            if (idx > 0 && ans[idx - 1] == 0) {
                q.push(idx - 1);
                ans[idx - 1] = ans[idx] + 1;
            }
            if (idx < n - 1 && ans[idx + 1] == 0) {
                q.push(idx + 1);
                ans[idx + 1] = ans[idx] + 1;
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};