// https://leetcode.com/problems/find-the-town-judge

#define umap unordered_map

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 && trust.size() == 0) return 1;
        set<int> trusters;
        umap<int, int> trusts;
        for (auto& x: trust) {
            trusters.insert(x[0]);
            trusts[x[1]]++;
        }
        for (auto& x: trusts) {
            if (trusters.find(x.first) == trusters.end() && x.second == n - 1) return x.first;
        }
        return -1;
    }
};