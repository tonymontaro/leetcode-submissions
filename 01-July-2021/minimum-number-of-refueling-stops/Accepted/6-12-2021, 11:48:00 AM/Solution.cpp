// https://leetcode.com/problems/minimum-number-of-refueling-stops

#define ll long long

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<ll> seenStations;
        stations.push_back({target, 0});
        ll dist = startFuel;
        int stops = 0;
        for (auto &station: stations) {
            while (!seenStations.empty() && dist < station[0]) {
                dist += seenStations.top();
                seenStations.pop();
                stops++;
            }
            if (dist >= station[0]) {
                seenStations.push(station[1]);
            } else 
                return -1;
        }
        return stops;
    }
};