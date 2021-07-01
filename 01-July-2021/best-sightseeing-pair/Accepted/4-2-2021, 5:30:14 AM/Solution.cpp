// https://leetcode.com/problems/best-sightseeing-pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = values[0];
        int idx = 0;
        int ans = 0;
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, values[i] + values[idx] - (i - idx));
            if (i + values[i] > best) {
                best = i + values[i];
                idx = i;
            }
        } 
        return ans;
    }
};