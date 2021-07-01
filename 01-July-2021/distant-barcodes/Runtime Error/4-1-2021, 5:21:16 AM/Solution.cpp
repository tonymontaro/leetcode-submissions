// https://leetcode.com/problems/distant-barcodes

#define v vector



class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes1) {
        int n = barcodes1.size();
        map<int, int> cnt;
        for (int i = 0; i < n; i++) cnt[barcodes1[i]]++;
        v<int> barcodes;
        v<pair<int, int>> ps;
        for (auto x: cnt) ps.push_back({-x.second, x.first});
        sort(ps.begin(), ps.end());
        for (auto x: ps) {
            for (int i = 0; i < -x.first; i++) barcodes.push_back(x.second);
        }
//        for (auto x: barcodes) cout << x << " ";
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