// https://leetcode.com/problems/freedom-trail

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        map<char, v<int>> indexes;
        int n = ring.size();
        for (int i = 0; i < ring.size(); i++) indexes[ring[i]].push_back(i);
        priority_queue<pii, v<pii>, greater<>> pq;
        int seen[100][100];
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++) seen[i][j] = INT_MAX;
        for (auto i: indexes[key[0]]) {
            int dist = min(i, n - i) + 1;
            seen[i][0] = dist;
            pq.push({dist, {i, 0}});
        }
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dist = node.first, ri = node.second.first, ki = node.second.second;
            if (ki == key.size() - 1) return dist;
            for (auto i: indexes[key[ki + 1]]) {
                int ndist = dist + min(abs(i - ri), min(ri + n - i, n - ri + i)) + 1;
                if (ndist < seen[i][ki + 1]) {
                    seen[i][ki + 1] = ndist;
                    pq.push({ndist, {i, ki + 1}});
                }
            }
        }
        return 0;
    }
};