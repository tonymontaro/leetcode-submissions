// https://leetcode.com/problems/sentence-similarity

#define umap unordered_map

class Solution {
public:
    bool areSentencesSimilar(vector<string>& a, vector<string>& b, vector<vector<string>>& sim) {
        if (a.size() != b.size()) return false;
        umap<string, set<string>> seen;
        for (auto& x: sim) {
            seen[x[0]].insert(x[1]);
            seen[x[1]].insert(x[0]);
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) continue;
            if (seen.find(a[i]) == seen.end() || seen[a[i]].find(b[i]) == seen[a[i]].end()) return false;
        }
        return true;
    }
};