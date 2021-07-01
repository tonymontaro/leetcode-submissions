// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

int maxArr(vector<int>& arr){
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++) ans = max(ans, arr[i]);
    return ans;
}





#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector


class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        v<bool> ans;
        ans.reserve(candies.size());
        int mx = maxArr(candies);
        for (int i = 0; i < candies.size(); i++) {
            ans.push_back(candies[i] + extraCandies >= mx);
        } 
        return ans;
    }
};