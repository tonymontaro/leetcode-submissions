// https://leetcode.com/problems/furthest-building-you-can-reach

#define v vector

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, v<int>, greater<>> pq;
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] < heights[i-1]) continue;
            int h = heights[i] - heights[i - 1];
            if (pq.size() < ladders) {
                pq.push(h);
                continue;
            }
            if (ladders > 0 && pq.top() < h) {
                int tmp = pq.top();
                pq.pop();
                pq.push(h);
                h = tmp;
            }
            if (h > bricks) return i - 1;
            bricks -= h;
        }
        return heights.size() - 1;
    }
};