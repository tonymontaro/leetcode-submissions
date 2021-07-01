// https://leetcode.com/problems/three-consecutive-odds

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cm = 0;
        for (auto x: arr) {
            if (x % 2 == 0) cm = 0;
            else cm++;
            if (cm == 3) return true;
        }
        return false;
    }
};