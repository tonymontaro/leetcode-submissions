// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        deque<pair<int, int>> st;
        for (int i = 0; i < prices.size(); ++i) {
            int p = prices[i];
            while (!st.empty() && p <= st.back().first) {
                ans[st.back().second] = st.back().first - p;
                st.pop_back();
            }
            st.push_back({p, i});
        }
        for (auto &x: st) ans[x.second] = x.first;
        return ans;
    }
};