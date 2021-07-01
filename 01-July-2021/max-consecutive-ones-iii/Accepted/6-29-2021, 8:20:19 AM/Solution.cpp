// https://leetcode.com/problems/max-consecutive-ones-iii

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> zeros;
        int left = 0, ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) zeros.push(i);
            if (zeros.size() > k) {
                left = zeros.front() + 1;
                zeros.pop();
            }
            ans = max(ans, i - left + 1);
        } 
        return ans;
    }
};