// https://leetcode.com/problems/number-of-segments-in-a-string

class Solution {
public:
    int countSegments(string s) {
        int ans = 0;
        int cnt = 0;
        for (auto x: s) {
            if (x == ' ') {
                if (cnt > 0) ans++;
                cnt = 0;
                continue;
            }
            cnt++;
        }
        if (cnt > 0) ans++;
        return ans;
    }
};