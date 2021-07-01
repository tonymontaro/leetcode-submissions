// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > 0 && ty > 0) {
            if (tx == sx && ty == sy)
                return true;
            int diff = abs(tx - ty);
            if (tx >= ty)
                tx = diff;
            else
                ty = diff;
        }
        return false;
    }
};