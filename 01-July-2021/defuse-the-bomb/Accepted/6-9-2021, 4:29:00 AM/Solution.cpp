// https://leetcode.com/problems/defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        int diff = k > 0 ? -1 : 1;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int rs = 0;
            for (int j = k; j != 0; j += diff) rs += code[(i + j + n) % n];
            ans[i] = rs;
        } 
        return ans;
    }
};