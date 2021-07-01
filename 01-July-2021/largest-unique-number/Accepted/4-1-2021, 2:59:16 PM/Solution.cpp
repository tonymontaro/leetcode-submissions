// https://leetcode.com/problems/largest-unique-number

class Solution {
public:
    int largestUniqueNumber(vector<int>& arr) {
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        int ans = -1;
        for (auto x: mp) {
            if (x.second > 1) continue;
            ans = max(ans, x.first);
        }
        return ans;
    }
};