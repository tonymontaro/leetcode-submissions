// https://leetcode.com/problems/jump-game-vi

#define ll long long
#define pi pair<ll, ll>


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pi> pq;
        pq.push({nums[0], 0});
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            while (i - pq.top().second > k) pq.pop();
            ans = pq.top().first + nums[i];
            pq.push({ans, i});
        }
        return ans;
    }
};