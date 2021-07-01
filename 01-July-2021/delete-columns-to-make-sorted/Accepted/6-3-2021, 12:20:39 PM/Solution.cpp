// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        for (int c = 0; c < strs[0].size(); c++) {
            char prev = 'A'; int res = 0;
            for (int i = 0; i < strs.size(); i++) {
                if (strs[i][c] < prev) {
                    res = 1; break;
                }
                prev = strs[i][c];
            } 
            ans += res;
        }
        return ans;
    }
};
