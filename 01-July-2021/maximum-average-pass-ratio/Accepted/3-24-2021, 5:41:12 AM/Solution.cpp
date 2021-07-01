// https://leetcode.com/problems/maximum-average-pass-ratio

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extra) {
        priority_queue<pair<double, pair<double, double>>> pq;
        for (auto x: classes) {
            double a = x[0], b = x[1];
            pq.push({((a + 1) / (b + 1)) - (a / b), {a, b}});
        }
        for (int i = 0; i < extra; i++) {
            auto node = pq.top();
            pq.pop();
            double a = node.second.first + 1, b = node.second.second + 1;
            pq.push({((a + 1) / (b + 1)) - (a / b), {a, b}});
        } 
        double total = 0;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            total += (node.second.first / node.second.second);
        }
        return total / classes.size();
    }
};