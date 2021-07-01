// https://leetcode.com/problems/largest-triangle-area

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (int i = 0; i < points.size(); i++) {
            double x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < points.size(); j++) {
                double x2 = points[j][0], y2 = points[j][1];
                for (int k = j + 1; k < points.size(); k++) {
                    double x3 = points[k][0], y3 = points[k][1];
                    double area = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
                    ans = max(area, ans);
                }
            }
        }
        return ans;
    }
};