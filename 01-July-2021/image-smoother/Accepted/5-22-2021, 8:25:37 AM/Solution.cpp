// https://leetcode.com/problems/image-smoother

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int rlen = img.size(), clen = img[0].size();
        vector<vector<int>> ans(rlen, vector<int>(clen));
        vector<vector<int>> dirs = {{1, 0}, {1, 1}, {1, -1}, {0, 0}, {0, 1}, {0, -1}, {-1, 0}, {-1, 1}, {-1, -1}};
        for (int row = 0; row < rlen; row++) {
            for (int col = 0; col < clen; col++) {
                int sm = 0;
                int cnt = 0;
                for (auto d: dirs){
                    int r = row + d[0], c = col + d[1];
                    if (r < 0 || r >= rlen || c < 0 || c >= clen) continue;
                    sm += img[r][c];
                    cnt++;
                }
                ans[row][col] = sm / cnt;
            }
        }
        return ans;
    }
};
