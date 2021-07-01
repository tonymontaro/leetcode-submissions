// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    int cache[10001];
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        memset(cache, -1, sizeof(cache));
        stack<int> st;
        for (auto x: nums2) {
            while (!st.empty() && x > st.top()) {
                cache[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }
        vector<int> ans;
        for (auto x: nums1) ans.push_back(cache[x]);
        return ans;
    }
};