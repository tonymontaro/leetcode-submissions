// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans[] = {0, 0};
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i > 0 && arr[i] != arr[i-1]) {
                if (cnt > ans[0]) {
                    ans[0] = cnt;
                    ans[1] = arr[i - 1];
                }
                cnt = 0;
            }
            cnt++;
        } 
        return cnt > ans[0] ? arr[arr.size() - 1] : ans[1];
    }
};