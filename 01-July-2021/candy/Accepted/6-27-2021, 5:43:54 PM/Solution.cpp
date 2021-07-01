// https://leetcode.com/problems/candy

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long


class Solution {
public:
    int candy(vector<int>& ratings) {
        v<pi> pq;
        pq.reserve(ratings.size());
        for (int i = 0; i < ratings.size(); i++) {
            pq.push_back({ratings[i], i});
        }
        sort(pq.begin(), pq.end());
        v<int> ans(ratings.size());
        for (int i = 0; i < ratings.size(); i++) {
            auto node = pq[i];
            int res = 1;
            int idx = node.second;
            if (idx > 0 && ratings[idx-1] < node.first) res = ans[idx-1] + 1;
            if (idx < ratings.size()-1 && ratings[idx + 1] < node.first) res = max(res, ans[idx+1] + 1);
            ans[idx] = res;
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};