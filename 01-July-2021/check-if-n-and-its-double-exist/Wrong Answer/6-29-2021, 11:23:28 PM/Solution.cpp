// https://leetcode.com/problems/check-if-n-and-its-double-exist

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        for (auto x: arr) if (st.find(x * 2) != st.end()) return true;
        return false;
    }
};