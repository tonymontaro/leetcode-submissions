// https://leetcode.com/problems/rabbits-in-forest

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> cnt;
        for (int i = 0; i < answers.size(); i++) {
            cnt[answers[i]]++;
        } 
        int ans = 0;
        for (auto [k, v]: cnt) {
            if (v > 1 && k + 1 >= v)
                ans += k + 1;
            else
                ans += ((k + 1) * v);
        }
        return ans;
    }
};