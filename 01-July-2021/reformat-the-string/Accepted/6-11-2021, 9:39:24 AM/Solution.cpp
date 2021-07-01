// https://leetcode.com/problems/reformat-the-string

class Solution {
public:
    string reformat(string s) {
        string ans;
        vector<char> nums;
        vector<char> alphas;
        for (auto x: s) if (isalpha(x))
                alphas.push_back(x);
            else
                nums.push_back(x);
        int diff = nums.size() - alphas.size();
        if (abs(diff) > 1) return "";
        int i = 0, j = 0, mx = max(nums.size(), alphas.size());
        if (nums.size() >= alphas.size()){
            for (int k = 0; k < mx; ++k) {
                if (i < nums.size()) ans += nums[i++];
                if (j < alphas.size()) ans += alphas[j++];
            }
        } else {
            for (int k = 0; k < mx; ++k) {
                if (j < alphas.size()) ans += alphas[j++];
                if (i < nums.size()) ans += nums[i++];
            }
        }
        return ans;
    }
};