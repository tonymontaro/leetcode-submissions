// https://leetcode.com/problems/sum-of-all-odd-length-subarrays

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans =0;
        for (int i = 0; i < arr.size(); i++) {
            int sm = 0;
            for (int k = i; k < arr.size(); k++) {
                sm += arr[k];
                if ((k - i) % 2 == 0) ans += sm;
            } 
        }
        return ans;
    }
};