// https://leetcode.com/problems/minimum-index-sum-of-two-lists

#define umap unordered_map

class Solution {
public:
    vector<string> findRestaurant(vector<string>& l1, vector<string>& l2) {
        vector<string> res;
        int sm = l1.size() + l2.size();
        umap<string, int> st;
        for (int i = 0; i < l1.size(); ++i) {
            st[l1[i]] = i;
        }
        for (int i = 0; i < l2.size(); ++i) {
            string x = l2[i];
            if (st.find(x) != st.end()) {
                if (i + st[x] == sm) res.push_back(x);
                else if (i + st[x] < sm) {
                    res = {x};
                    sm = i + st[x];
                }
            }
        } 
        return res;
    }
};