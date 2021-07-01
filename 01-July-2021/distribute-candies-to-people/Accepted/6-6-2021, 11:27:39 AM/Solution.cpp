// https://leetcode.com/problems/distribute-candies-to-people

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int total = 0, i = 0;
        while (candies > 0) {
            total = min(total + 1, candies);
            ans[i] += total;
            candies -= total;
            i = (i + 1) % num_people;
        }
        return ans;
    }
};