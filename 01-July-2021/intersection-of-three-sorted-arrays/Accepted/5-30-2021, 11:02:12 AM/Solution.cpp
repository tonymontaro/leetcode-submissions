// https://leetcode.com/problems/intersection-of-three-sorted-arrays

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> count;
        vector<vector<int>> arrs = {arr1, arr2, arr3};
        for (auto &arr: arrs) {
            for (auto num: arr) count[num]++;
        }
        vector<int> ans;
        for (auto [num, cnt]: count) if (cnt == 3) ans.push_back(num);
        return ans;
    }
};