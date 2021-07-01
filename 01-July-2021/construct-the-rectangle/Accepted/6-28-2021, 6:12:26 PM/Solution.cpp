// https://leetcode.com/problems/construct-the-rectangle

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i = 1;
        int res = 1;
        int diff = area - res;
        while (i * i <= area) {
            if (area % i == 0) {
                int df = (area / i) - i;
                if (df < diff) {
                    diff = df;
                    res = i;
                }
            }
            i++;
        }
        return {area / res, res};
    }
};
