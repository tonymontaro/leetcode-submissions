// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for (int i = num.size()-1; i >= 0; --i) {
            int val = carry + num[i] + k % 10;
            carry = val / 10;
            k /= 10;
            num[i] = val % 10;
        }
        vector<int> ans;
        ans.reserve(num.size() + 1);
        if (carry > 0) ans.push_back(carry);
        for (int i = 0; i < num.size(); i++) ans.push_back(num[i]);
        return ans;
    }
};