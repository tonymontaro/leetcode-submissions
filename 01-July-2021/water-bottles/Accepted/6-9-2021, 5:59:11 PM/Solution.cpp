// https://leetcode.com/problems/water-bottles

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;
        int empty = numBottles;
        while (empty >= numExchange) {
            total += empty / numExchange;
            int mod = empty % numExchange;
            empty = (empty / numExchange) + mod;
        }
        return total;
    }
};
