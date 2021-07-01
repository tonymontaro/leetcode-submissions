// https://leetcode.com/problems/number-of-different-subsequences-gcds

#define v vector


int inarr[200001];
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        memset(inarr, 0, sizeof(inarr));
        set<int> seen;
        int mx = 0;
        for (auto x: nums) {
            inarr[x] = 1;
            seen.insert(x);
            mx = max(mx, x);
        }
        v<int> arr;
        arr.reserve(seen.size());
        map<int, int> mpIdx;
        int idx = 0;
        for (auto x: seen) {
            arr.push_back(x);
            mpIdx[x] = idx++;
        }

        int ans = seen.size();
        for (int x = mx - 1; x >= 1; x--) {
            if (inarr[x] == 1) continue;
            int num = x;
            v<int> valid;
            while (num <= mx) {
                if (inarr[num] == 1) valid.push_back(num);
                num += x;
            }

            if (valid.size() <= 1) continue;
            int gd = valid[0];
            for (int i = 1; i < valid.size(); i++) {
                gd = gcd(gd, valid[i]);
            }

            if (inarr[x] == 0 && gd == x) ans++;
        }
        return ans;
    }
};
