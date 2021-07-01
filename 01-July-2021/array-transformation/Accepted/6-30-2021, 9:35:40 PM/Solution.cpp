// https://leetcode.com/problems/array-transformation


class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int n = arr.size();
        bool changed = true;
        while (changed) {
            changed = false;
            vector<int> res;
            res.reserve(n);
            for (int i = 0; i < n; i++) {
                if (i == 0 || i == n - 1) {
                    res.push_back(arr[i]); continue;
                }
                if (arr[i-1] > arr[i] && arr[i+1] > arr[i]) {
                    changed = true;
                    res.push_back(arr[i] + 1);
                } else if (arr[i-1] < arr[i] && arr[i+1] < arr[i]) {
                    changed = true;
                    res.push_back(arr[i] - 1);
                } else res.push_back(arr[i]);
            }
            arr = res;
        }
        return arr;
    }
};