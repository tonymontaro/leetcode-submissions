// https://leetcode.com/problems/palindrome-pairs

#define umap unordered_map

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        umap<string, int> widx;
        int n = words.size();
        for (int i = 0; i < n; i++) widx[words[i]] = i;
        for (int i = 0; i < n; i++) {
            string w = words[i];
            if (w.empty()) {
                for (int j = 0; j < n; j++) {
                    if (ispal(words[j], 0, words[j].size()-1) && j != i) {
                        ans.push_back({i, j});
                        ans.push_back({j, i});
                    }
                }
                continue;
            }
            string rev = w; reverse(rev.begin(), rev.end());
            if (widx.find(rev) != widx.end() && widx[rev] != i) ans.push_back({i, widx[rev]});
            for (int j = 1; j < w.size(); j++) {
                if (ispal(w, 0, j-1)) {
                    rev = w.substr(j); reverse(rev.begin(), rev.end());
                    if (widx.find(rev) != widx.end()) ans.push_back({widx[rev], i});
                }
                if (ispal(w, j, w.size()-1)) {
                    rev = w.substr(0, j); reverse(rev.begin(), rev.end());
                    if (widx.find(rev) != widx.end()) ans.push_back({i, widx[rev]});
                }
            }
        }
        return ans;
    }
    bool ispal(string& w, int s, int e) {
        while (s < e) {
            if (w[s++] != w[e--]) return false;
        }
        return true;
    }
};