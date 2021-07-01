// https://leetcode.com/problems/minimum-area-rectangle-ii

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector



class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double ans = INT_MAX;
        set<pair<int, int>> seen;
        for (auto x: points) seen.insert({x[0], x[1]});

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    double ij = distance(points[i], points[j]);
                    double jk = distance(points[j], points[k]);
                    if (ij + jk != distance(points[i], points[k])) continue;
                    int x = points[i][0] + points[k][0] - points[j][0];
                    int y = points[i][1] + points[k][1] - points[j][1];
                    if (seen.find({x, y}) == seen.end()) continue;

                    double res = sqrt(ij) * sqrt(jk);
                    ans = min(ans, res);
                }
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
    double distance(v<int> &p1, v<int> &p2) {
        double x = p1[0] - p2[0];
        double y = p1[1] - p2[1];
        return (x * x) + (y * y);
    }
};