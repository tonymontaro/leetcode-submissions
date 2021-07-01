// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int prev = -1;
        for (int i = arr.size() - 1; i >= 0; --i) {
            int tmp = max(prev, arr[i]);
            arr[i] = prev;
            prev = tmp;
        }
        return arr;
    }
};