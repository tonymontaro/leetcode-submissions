// https://leetcode.com/problems/advantage-shuffle

#define v vector

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        v<pair<int, int>> arr;
        for (int i = 0; i < A.size(); i++) arr.push_back({B[i], i});
        sort(arr.begin(), arr.end());
        sort(A.begin(), A.end());
        int idx = 0, ridx = 0;
        v<int> rem;
        v<int> ans(B.size(), -1);
        for (auto x: arr) {
            while (idx < A.size() && A[idx] <= x.first) {
                rem.push_back(A[idx]);
                idx++;
            }
            if (idx < A.size())
                ans[x.second] = A[idx++];
            else
                ans[x.second] = rem[ridx++];
        }
        return ans;
    }
};
