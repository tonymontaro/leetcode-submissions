// https://leetcode.com/problems/powerful-integers

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans;
        int xval = 1;
        for (int i = 0; i < 24; i++) {
            if (xval > bound) break;
            int yval = 1;
            for (int j = 0; j < 24; j++) {
                int rs = xval + yval;
                if (rs > bound) break;
                ans.insert(rs);
                yval *= y;
            }
            xval *= x;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};