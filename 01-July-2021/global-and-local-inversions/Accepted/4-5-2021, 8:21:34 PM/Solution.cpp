// https://leetcode.com/problems/global-and-local-inversions

class Solution {
public:
    bool isIdealPermutation(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return true;

        int mn = min(arr[0], arr[1]);
        int idx = 0;
        while (idx < n) {
            if (arr[idx] < mn || (idx < n - 1 && arr[idx + 1] < mn)) return false;
            mn = arr[idx];
            if (idx < n - 1 && arr[idx] > arr[idx + 1])
                idx += 2;
            else
                idx += 1;
        }
        return true;
    }
};