// https://leetcode.com/problems/candy

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long


class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pi, v<pi>, greater<>> pq;
        for (int i = 0; i < ratings.size(); i++) {
            pq.push({ratings[i], i});
        }
        v<int> ans(ratings.size());
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int res = 1;
            int idx = node.second;
            if (idx > 0 && ratings[idx-1] < node.first) res = ans[idx-1] + 1;
            if (idx < ratings.size()-1 && ratings[idx + 1] < node.first) res = max(res, ans[idx+1] + 1);
            ans[idx] = res;
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};