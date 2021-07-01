// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int x = nums[n-3], y = nums[n-2], z = nums[n-1];
        int a= nums[0], b = nums[1], c = nums[2];
        int ans = max(x*y*z, z*a*b);
        return ans;
    }
};