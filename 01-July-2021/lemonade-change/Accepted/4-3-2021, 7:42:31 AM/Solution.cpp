// https://leetcode.com/problems/lemonade-change

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> available;
        for (auto bill: bills) {
            if (bill == 5) {
                available[5]++;
            } else if (bill == 10) {
                if (available[5] <= 0) return false;
                available[5]--;
                available[10]++;
            } else if (bill == 20) {
                int cnt = 3;
                if (available[10] > 0) {
                    cnt -= 2;
                    available[10]--;
                }
                if (available[5] < cnt) return false;
                available[5] -= cnt;
            }
        }
        return true;
    }
};