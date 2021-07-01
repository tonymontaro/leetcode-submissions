// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        for (int i = 0; i < data.size(); i++) if (data[i] == 1) ones++;
        int zeros = 0;
        for (int i = 0; i < ones; i++) if (data[i] == 0) zeros++;
        int best = zeros;
        for (int i = ones; i < data.size(); i++) {
            if (data[i - ones] == 0) zeros--;
            if (data[i] == 0) zeros++;
            best = min(zeros, best);
        } 
        return best;
    }
};