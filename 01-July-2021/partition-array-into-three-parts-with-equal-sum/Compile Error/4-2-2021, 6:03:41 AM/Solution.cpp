// https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sm = sumArr(arr);
        if (sm % 3 != 0) return false;
        int part = sm / 3;
        int cm = 0;
        int left = -1;
        for (int i = 0; i < arr.size(); i++) {
            cm += arr[i];
            if (cm == part) {
                left = i;
                break;
            }
        } 
        if (left == -1) return false;
        int right = -1;
        cm = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            cm += arr[i];
            if (cm == part) {
                right = i;
                break;
            }
        }
        return !(right == -1 || left + 1 >= right);
    }
};