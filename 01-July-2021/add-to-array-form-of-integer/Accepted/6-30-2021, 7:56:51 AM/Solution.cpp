// https://leetcode.com/problems/add-to-array-form-of-integer

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0, i = num.size()-1;
        while (k > 0 || i >= 0 || carry > 0) {
            int val = carry;
            if (k > 0) {
                val += k % 10; k /= 10;
            }
            if (i >= 0) val += num[i--];
            carry = val / 10;
            ans.push_back(val % 10);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};