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
        ans[0] = 1;
        int n = ratings.size();
        for (int i = 1; i < n; i++) {
            ans[i] = ratings[i] > ratings[i-1] ? ans[i-1]+1 : 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) ans[i] = max(ans[i], ans[i+1] + 1);
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};