// https://leetcode.com/problems/minimum-absolute-sum-difference

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector



class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        ll total = 0;
        ll mod = 1e9 + 7;
        int mx = INT_MIN, mn = INT_MAX;
        int diff = INT_MAX;
        set<int> st;
        for (int i = 0; i < nums1.size(); i++) {
            st.insert(nums1[i]);
            mx = max(mx, nums1[i]);
            mn = min(mn, nums1[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            int a = nums1[i], b = nums2[i];
            int df = abs(a - b);
            total = (total + df) % mod;
            auto low = st.lower_bound(b);

            if (low == st.end()) {
                diff = min(diff, abs(mx - b) - df);
            } else {
                diff = min(diff, abs(*low - b) - df);
                if (low != st.begin()) {
                    low--;
                    diff = min(diff, abs(*low - b) - df);
                }
            }
        }
        return (total + diff + mod) % mod;
    }
};
