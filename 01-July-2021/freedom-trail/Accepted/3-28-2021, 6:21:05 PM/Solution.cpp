// https://leetcode.com/problems/freedom-trail

#define v vector

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        map<char, v<int>> chs;
        int n = ring.size();
        for (int i = 0; i < ring.size(); i++) chs[ring[i]].push_back(i);
        priority_queue<pair<int, pair<int, int>>, v<pair<int, pair<int, int>>>, greater<>> pq; // dist, key[idx]
        int seen[100][100];
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++) seen[i][j] = INT_MAX;

        for (int idx: chs[key[0]]) {
            int dist = min(idx, n - idx) + 1;
            pq.push({dist, {idx, 0}});
            seen[idx][0] = dist;
        }
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int dist = node.first, ridx = node.second.first, kidx = node.second.second;

            if (kidx == key.size() - 1) return dist;
            for (int idx: chs[key[kidx + 1]]) {

                int nextDist = 1 + dist + min(abs(idx - ridx), min(ridx + n - idx, n - ridx + idx));
                if (nextDist < seen[idx][kidx + 1]) {
                    seen[idx][kidx + 1] = nextDist;
                    pq.push({nextDist, {idx, kidx + 1}});
                }
            }
        }
        return 0;
    }
};