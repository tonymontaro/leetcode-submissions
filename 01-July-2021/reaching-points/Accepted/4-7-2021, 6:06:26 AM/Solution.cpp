// https://leetcode.com/problems/reaching-points

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > 0 && ty > 0) {
            if (tx == sx && ty == sy)
                return true;
            if (tx < sx || ty < sy) return false;

            int div = tx / ty;
            if (tx >= ty) {
                if (ty == sy && (tx - sx) % ty == 0) return true;
                tx = tx - (div * ty);
            } else {
                if (tx == sx && (ty - sy) % tx == 0) return true;
                div = ty / tx;
                ty = ty - (div * tx);
            }
        }
        return false;
    }
};
