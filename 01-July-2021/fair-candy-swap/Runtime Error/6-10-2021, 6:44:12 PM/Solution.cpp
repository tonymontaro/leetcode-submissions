// https://leetcode.com/problems/fair-candy-swap

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int seen[10001] = {0};
        int a = 0;
        for (auto x: aliceSizes) {
            a += x;
            seen[x] = 1;
        }
        int b = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        for (auto x: bobSizes) {
            int other = a - b + 2*x;
            int y = other/2;
            if (other < 0 || other % 2 == 1 || !seen[y]) continue;
            if (a - y + x != b - x + y) continue;
            return {y, x};
        }
        return {0, 0};
    }
};