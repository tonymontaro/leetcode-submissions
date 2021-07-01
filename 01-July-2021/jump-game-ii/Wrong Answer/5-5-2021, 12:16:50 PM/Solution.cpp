// https://leetcode.com/problems/jump-game-ii

#define pi pair<int, int>
#define v vector



class Solution {
public:
    int jump(vector<int>& nums) {
        pi jump = {1, nums[0]};
        pi nxt = {2, 0};
        for (int i = 1; i < nums.size(); i++) {
            if (jump.second < i) {
                jump = {nxt.first, nxt.second};
                nxt.first++;
            }
            if (i + nums[i] > nxt.second) nxt.second = i + nums[i];
        } 
        return jump.first;
    }
};

