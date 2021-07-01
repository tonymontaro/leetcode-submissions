// https://leetcode.com/problems/beautiful-arrangement-ii

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> arr;
        arr.reserve(n);
        int left = 1, right = n;
        while (k > 0) {
            if (k == 1) {
                for (int i = left; i < right + 1; i++) arr.push_back(i);
                return arr;
            }
            if (k == 2) {
                for (int i = left; i < right - 1; i++) arr.push_back(i);
                arr.push_back(right);
                arr.push_back(right - 1);
                return arr;
            }
            k -= 2;
            arr.push_back(left++);
            arr.push_back(right--);
        }
        return arr;
    }
};