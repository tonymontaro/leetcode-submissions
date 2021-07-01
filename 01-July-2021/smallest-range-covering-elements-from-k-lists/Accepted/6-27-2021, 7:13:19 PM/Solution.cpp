// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int mx = -1e6;
        priority_queue<pii, v<pii>, greater<>> pq;
        for (int i = 0; i < nums.size(); i++) {
            mx = max(mx, nums[i][0]);
            pq.push({nums[i][0], {i, 0}});
        }
        int mn = pq.top().first;
        v<int> ans = {mx, mn};
        while (true) {
            auto last = pq.top();
            pq.pop();
            int aidx = last.second.first;
            int idx = last.second.second;
            if (idx == nums[aidx].size() - 1) break;
            int val = nums[aidx][idx + 1];
            mx = max(mx, val);
            pq.push({val, {aidx, idx + 1}});
            mn = pq.top().first;
            if (mx - mn < ans[0] - ans[1]) ans = {mx, mn};
        }
        return {ans[1], ans[0]};
    }
};