// https://leetcode.com/problems/minimum-area-rectangle-ii

#define v vector

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        int n = points.size();
        double ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    for (int l = 0; l < n; l++) {
                        if (l == i || l == j || l == k) continue;
                        auto s1 = getSlope(points[i], points[j]);
                        auto s2 = getSlope(points[i], points[k]);
                        auto s3 = getSlope(points[j], points[l]);
                        auto s4 = getSlope(points[k], points[l]);
                        if (s1 == s4 && s2 == s3) {
                            auto dist = getDistance(points[i], points[j]) * getDistance(points[j], points[l]);
                            ans = min(ans, dist);
                        }
                    }
                }
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
    double getDistance(v<int> &p1, v<int> &p2) {
        double x1 = p1[0], y1 = p1[1], x2 = p2[0], y2 = p2[1];
        double a = abs(x1 - x2);
        double b = abs(y1 - y2);
        return sqrt(a * a + b * b);
    }

    pair<int, int> getSlope(v<int> &p1, v<int> &p2){
        if (p1[0] == p2[0]) return {60000 + min(p1[1], p2[1]), 60000 + max(p1[1], p2[1])};
        if (p1[1] == p2[1]) return {50000 + min(p1[0], p2[0]), 50000 + max(p1[0], p2[0])};
        int a = p1[1] - p2[1], b = p1[0] - p2[0];
        if (a < 0) {
            a = a * -1;
            b = b * -1;
        }
        int gd = gcd(a, abs(b));
        return {a / gd, b / gd};
    }
};
