// https://leetcode.com/problems/distance-between-bus-stops

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int total = accumulate(distance.begin(), distance.end(), 0);
        int dist = 0;
        int a = min(start, destination), b = max(start, destination);
        for (int i = a; i < b; i++) dist += distance[i];
        return min(dist, total - dist);
    }
};