// https://leetcode.com/problems/binary-gap

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        while (n > 0 && (n & 1) == 0) n >>= 1;
        int i = 0, prev = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                ans = max(ans, i - prev);
                prev = i;
            }
            i++;
            n >>= 1;
        }
        return ans;
    }
};