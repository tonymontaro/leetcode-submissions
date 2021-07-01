// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        int dp[501][501];
        memset(dp, -1, sizeof(dp));
        int d = startFuel;
        for (int stops = 0; stops < n + 1; stops++) {
            for (int i = stops; i < n; i++) {
                if (stations[i][0] > d) break;
                dp[i][stops + 1] = d + stations[i][1];
                d = max(d, dp[i][stops]);
            }
            if (d >= target) return stops;
            d = dp[stops][stops + 1];
            if (d == -1) break;
        }
        return -1;
    }
};