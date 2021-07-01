// https://leetcode.com/problems/minimum-number-of-refueling-stops

#define ll long long

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        ll n = stations.size();
        ll dp[501][501];
        memset(dp, -1, sizeof(dp));
        ll d = startFuel;
        for (ll stops = 0; stops < n + 1; stops++) {
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