// https://leetcode.com/problems/find-anagram-mappings

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> seen;
        for (int i = 0; i < nums2.size(); i++) seen[nums2[i]] = i;
        vector<int> ans;
        ans.reserve(nums2.size());
        for (auto x: nums1) {
            ans.push_back(seen[x]);
        }
        return ans;
    }
};