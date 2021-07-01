// https://leetcode.com/problems/maximum-units-on-a-truck

bool compare(vector<int>& a, vector<int>& b) {
    if (b[1] > a[1]) return false;
    return a[1] > b[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compare);
        int ans = 0;
        for (auto& x: boxTypes) {
            if (truckSize == 0) break;
            int diff = min(truckSize, x[0]);
            truckSize -= diff;
            ans += diff * x[1];
        }
        return ans;
    }
};