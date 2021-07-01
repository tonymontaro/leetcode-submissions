// https://leetcode.com/problems/shortest-distance-to-target-color

int forwad[50001][3];
int backward[50001][3];
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        memset(forwad, -1, sizeof(forwad));
        memset(backward, -1, sizeof(backward));
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            int num = colors[i];
            for (int j = 0; j < 3; ++j) {
                if (i > 0) forwad[i][j] = forwad[i-1][j];
            }
            forwad[i][num-1] = i;
        }
        for (int i = n -1; i >= 0; --i) {
            int num = colors[i];
            for (int j = 0; j < 3; ++j) {
                if (i < n -1) backward[i][j] = backward[i+1][j];
            }
            backward[i][num-1] = i;
        }
        vector<int> ans;
        for (auto &q: queries) {
            int res = INT_MAX;
            if (forwad[q[0]][q[1]-1] != -1) res = q[0] - forwad[q[0]][q[1] - 1];
            if (backward[q[0]][q[1]-1] != -1) res = min(backward[q[0]][q[1] - 1] - q[0], res);
            ans.push_back(res == INT_MAX ? -1 :res);
        }
        return ans;
    }
};