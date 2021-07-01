// https://leetcode.com/problems/jump-game-ii

#define pi pair<int, int>
#define v vector



class Solution {
public:
    int jump(vector<int>& nums) {
        priority_queue<pi, v<pi>, greater<>> pq;
        pq.push({0, 0});
        for (int i = 0; i < nums.size(); i++) {
            while (i > pq.top().second) pq.pop();
            pq.push({pq.top().first + 1, i + nums[i]});
        }
        return pq.top().first;
    }
};