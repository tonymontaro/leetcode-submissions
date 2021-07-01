// https://leetcode.com/problems/grumpy-bookstore-owner

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int k) {
        int total = 0;
        int best = 0, current = 0;
        int left = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (i - left == k) {
                if (grumpy[left] == 1) current -= customers[left];
                left++;
            }
            if (grumpy[i] == 0) total += customers[i];
            else current += customers[i];
            best = max(best, current);
        } 
        return total + best;
    }
};