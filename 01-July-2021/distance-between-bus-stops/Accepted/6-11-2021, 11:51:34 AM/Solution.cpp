// https://leetcode.com/problems/distance-between-bus-stops

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        for (int i = 1; i < distance.size(); i++) distance[i] += distance[i - 1];
        if (start > destination) swap(start, destination);
        int dist = start == 0 ? distance[destination - 1] : distance[destination - 1] - distance[start - 1];
        return min(dist, distance[distance.size()-1] - dist);
    }
};