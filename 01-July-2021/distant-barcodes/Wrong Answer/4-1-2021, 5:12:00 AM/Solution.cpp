// https://leetcode.com/problems/distant-barcodes

#define v vector



class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        sort(barcodes.begin(), barcodes.end());
        int n = barcodes.size();
        if (n <= 2) return barcodes;
        v<int> ans;
        int ad = (n % 2 == 1) ? 1 : 0;
        int half = n / 2;
        for (int i = 0; i < half; i++) {
            ans.push_back(barcodes[i]);
            ans.push_back(barcodes[half + i + ad]);
        }
        if (n % 2 == 1) {
            int mid = barcodes[half];
            if (ans[ans.size() - 1] != mid) ans.push_back(mid);
            else {
                v<int> nans = {mid};
                nans.insert(nans.end(), ans.begin(), ans.end());
                return nans;
            }
        }
        return ans;
    }
};