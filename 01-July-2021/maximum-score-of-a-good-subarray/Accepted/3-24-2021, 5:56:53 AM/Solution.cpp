// https://leetcode.com/problems/maximum-score-of-a-good-subarray

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int mn = nums[k];
        ll ans = mn;
        int left = k - 1, right = k + 1;
        while (left >= 0 || right < n) {
            if (right >= n || (left >= 0 && nums[left] >= nums[right])){
                mn = min(mn, nums[left]);
                left--;
            } else {
                mn = min(mn, nums[right]);
                right++;
            }
            ll score = (right - left - 1) * mn;
            ans = max(ans, score);
        }
        return ans;
    }
};