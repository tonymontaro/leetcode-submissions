// https://leetcode.com/problems/construct-target-array-with-multiple-sums

#define ll long long

class Solution {
public:
    bool isPossible(vector<int>& target) {
        ll n = target.size();
        ll total = 0;
        priority_queue<ll> pq;
        for (auto x: target) {
            total += x;
            pq.push(x);
        }
        while (total > n) {
            auto tp = pq.top();
            pq.pop();
            total -= tp;
            if (total >= tp) return false;
            auto nx = tp - ((tp / total) * total);
            if (nx == 0) nx += total;
            total += nx;
            pq.push(nx);
        }
        
        return true;
    }
};