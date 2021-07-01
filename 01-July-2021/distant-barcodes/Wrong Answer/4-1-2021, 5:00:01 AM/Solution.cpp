// https://leetcode.com/problems/distant-barcodes

#define v vector

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(), barcodes.end());
        int n = barcodes.size();
        v<int> ans;
        if (n % 2 == 1) ans.push_back(barcodes[n - 1]);
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            ans.push_back(barcodes[i]);
            ans.push_back(barcodes[half + i]);
        } 
        return ans;
    }
};