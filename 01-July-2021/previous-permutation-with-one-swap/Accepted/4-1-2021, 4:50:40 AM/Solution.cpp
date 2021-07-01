// https://leetcode.com/problems/previous-permutation-with-one-swap

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int mn = INT_MAX;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int num = arr[i];
            if (num > mn){
                for (int j = i + 1; j < arr.size(); j++){
                    if (arr[j] < num)
                        mn = max(mn, arr[j]);
                }
                for (int j = i + 1; j < arr.size(); j++) {
                    if (arr[j] == mn) {
                        swap(arr[j], arr[i]);
                        break;
                    }
                }
                break;
            }
            mn = min(mn, num);
        }
        return arr;
    }
};