// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        int zeros = 0;
        for (auto x: arr) {
            if (x == 0) {
                zeros++; continue;
            }
            if (st.find(x * 2) != st.end()) return true;
        }
        return zeros > 1;
    }
};
