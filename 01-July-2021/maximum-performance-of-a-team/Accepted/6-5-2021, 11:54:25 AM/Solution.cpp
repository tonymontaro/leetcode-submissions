// https://leetcode.com/problems/maximum-performance-of-a-team

#define ll long long
#define pi pair<ll, ll>
#define v vector

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        ll mod = 1e9 + 7;
        v<pi> items;
        items.reserve(n);
        for (int i = 0; i < n; i++) items.emplace_back(efficiency[i], speed[i]);
        sort(items.begin(), items.end(), greater<>());
        priority_queue<ll, v<ll>, greater<>> pq;
        ll total = 0, ans = 0;
        for (auto &item: items) {
            ans = max(ans, (total + item.second) * item.first);
            total += item.second;
            pq.push(item.second);
            if (pq.size() >= k) {
                total -= pq.top();
                pq.pop();
            }
        }
        return (ans % mod);
    }
};