// https://leetcode.com/problems/longest-string-chain

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector


bool compare(string &a, string &b) {
    if (b.length() > a.length()) return false;
    return a.length() > b.length();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        umap<string, int> seen;
        for (auto &w: words) seen[w] = 1;
        sort(words.begin(), words.end(), compare);
        int ans = 0;
        for (auto &w: words) {
            int num = seen[w];
            for (int i = 0; i < w.size(); i++) {
                string s = w.substr(0, i) + w.substr(i + 1);
                if (seen.find(s) != seen.end()) seen[s] = max(seen[s], 1 + num);
            }
            ans = max(ans, num);
        }
        return ans;
    }
};