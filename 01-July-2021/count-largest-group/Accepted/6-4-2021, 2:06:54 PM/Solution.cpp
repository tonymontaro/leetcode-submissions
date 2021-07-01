// https://leetcode.com/problems/count-largest-group

#define umap unordered_map

class Solution {
public:
    int countLargestGroup(int n) {
        umap<int, int> cnt; int mx = 0;
        for (int i = 1; i < n + 1; i++) {
            int num = i, sm = 0;
            while (num > 0) {
                sm += num % 10;
                num /= 10;
            }
            cnt[sm]++;
            mx = max(mx, cnt[sm]);
        }
        int ans = 0;
        for (auto x: cnt) if (x.second == mx) ans++;
        return ans;
    }
};