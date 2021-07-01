// https://leetcode.com/problems/word-subsets

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define v vector

umap<char, int> getCount(string &s) {
    umap<char, int> cnt;
    for (int i = 0; i < s.size(); i++) cnt[s[i]]++;
    return cnt;
}

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        umap<char, int> count;
        for (auto &x: B) {
            auto cnt = getCount(x);
            for (auto y: cnt) count[y.first] = max(count[y.first], y.second);
        }
        v<string> ans;
        ans.reserve(A.size());
        for (auto &word: A) {
            auto cnt = getCount(word);
            bool valid = true;
            for (auto x: count) {
                if (cnt[x.first] < x.second) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.push_back(word);
        }
        return ans;
    }
};