// https://leetcode.com/problems/defuse-the-bomb

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n);
        if (k == 1) return ans;
        int front = k > 0 ? k : -1;
        int back = k > 0 ? 1 : k;
        int rs = 0;
        for (int i = back; i <= front; i++) rs += code[(i + n) % n]; 
        for (int i = 0; i < n; i++) {
            ans[i] = rs;
            rs += code[(++front + n) % n];
            rs -= code[(back++ + n) % n];
        }
        return ans;
    }
};