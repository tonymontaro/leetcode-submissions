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
            int vv = (v + k) / (k + 1); 
            
            ans += ((k + 1) * vv);
        }
        return ans;
    }
};