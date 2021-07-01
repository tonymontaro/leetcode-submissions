// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a;
        for (auto x: nums1) a.insert(x);
        set<int> ans;
        for (auto x: nums2) {
            if (a.find(x) != a.end()) ans.insert(x);
        }
        return vector<int>(ans.begin(), ans.end());
    }
};