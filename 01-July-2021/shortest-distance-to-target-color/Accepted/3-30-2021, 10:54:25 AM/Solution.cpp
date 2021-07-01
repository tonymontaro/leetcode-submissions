// https://leetcode.com/problems/shortest-distance-to-target-color

#define v vector
string delim = " ";
#define print(x) cout << x << endl;
#define print2(x, y) cout << x << delim << y << endl;
#define print3(x, y, z) cout << x << delim << y << delim << z << endl;


class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        v<int> cc = {-1, -1, -1};
        int dist[n][3];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++) dist[i][j] = INT_MAX;
        for (int i = 0; i < n; i++) {
            cc[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++) if (cc[j] > -1) dist[i][j] = (i - cc[j]);
            // print3(dist[i][0], dist[i][1], dist[i][2])
        }

        cc = {-1, -1, -1};
        for (int i = n - 1; i >= 0; i--) {
            cc[colors[i] - 1] = i;
            for (int j = 0; j < 3; j++) if (cc[j] > -1) dist[i][j] = min(dist[i][j], cc[j] - i);
            // print3(dist[i][0], dist[i][1], dist[i][2])
        }
        v<int> ans;
        ans.reserve(queries.size());
        for (auto x: queries) {
            int rs = dist[x[0]][x[1] - 1];
            ans.push_back((rs == INT_MAX) ? -1 : rs);
        }
        return ans;
    }
};