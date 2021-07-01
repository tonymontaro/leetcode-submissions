// https://leetcode.com/problems/maximum-product-of-word-lengths

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector



class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int, ll>> items;
        for (auto const& word: words) {
            ll num = 0;
            for (auto c: word)
                num = num | (1 << (c - 'a'));
            items.emplace_back(word.size(), num);
        }
        int ans = 0;
        for (auto const& a: items) {
            for (auto const& b: items) {
                if ((a.second & b.second) == 0)
                    ans = max(ans, a.first * b.first);
            }
        }
        return ans;
    }
};