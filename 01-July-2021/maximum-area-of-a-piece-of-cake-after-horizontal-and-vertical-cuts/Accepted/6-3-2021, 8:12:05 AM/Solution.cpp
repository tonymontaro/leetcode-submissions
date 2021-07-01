// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts

#define ll long long

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        ll prevH = 0; ll bestH = 0;
        for (auto& cut: horizontalCuts) {
            bestH = max(bestH, cut - prevH);
            prevH = cut;
        }
        ll prevV = 0; ll bestV = 0;
        for (auto& cut: verticalCuts) {
            bestV = max(bestV, cut - prevV);
            prevV = cut;
        }
        ll mod = 1e9 + 7;
        return (bestH * bestV) % mod;
    }
};