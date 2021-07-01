// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& grid, int target) {
        int rlen = grid.size(), clen = grid[0].size();
        int ans = 0;
        for (int rows = 1; rows < rlen + 1; rows++) {
            int arr[clen + 1];
            memset(arr, 0, sizeof(arr));
            for (int r = 0; r < rows - 1; r++)
                for (int c = 0; c < clen; c++)
                    arr[c + 1] += grid[r][c];
            int top = 0;
            for (int r = rows - 1; r < rlen; r++) {
                map<int, int> seen;
                seen[0] = 1;
                int presum = 0;
                for (int c = 0; c < clen; c++) {
                    arr[c + 1] += grid[r][c];
                    presum += arr[c + 1];
                    ans += seen[presum - target];
                    seen[presum]++;
                    arr[c + 1] -= grid[top][c];
                }
                top++;
            }
        }
        return ans;
    }
};