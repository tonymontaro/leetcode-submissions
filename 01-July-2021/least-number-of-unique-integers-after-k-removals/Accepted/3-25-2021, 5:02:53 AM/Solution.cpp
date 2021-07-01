// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector


class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        umap<int, int> cnt;
        for (auto x: arr) cnt[x]++;
        v<int> nums;
        for (auto x: cnt) nums.push_back(x.second);
        sort(nums.begin(), nums.end());
        int idx = 0;
        while (idx < nums.size()) {
            if (nums[idx] > k) return nums.size() - idx;
            k -= nums[idx++];
        }
        return 0;
    }
};