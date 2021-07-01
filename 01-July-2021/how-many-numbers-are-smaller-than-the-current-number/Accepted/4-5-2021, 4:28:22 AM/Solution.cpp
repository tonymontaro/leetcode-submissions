// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

#define v vector


class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        v<int> ans;
        ans.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) 
                if (nums[i] > nums[j]) cnt++;
            ans.push_back(cnt);
        } 
        return ans;
    }
};