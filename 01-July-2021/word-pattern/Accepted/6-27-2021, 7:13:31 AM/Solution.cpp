// https://leetcode.com/problems/word-pattern

vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}

#define umap unordered_map
#define uset unordered_set

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        v<string> words = splitWord(s);
        if (words.size() != pattern.size()) return false;
        umap<char, string> seen;
        umap<string, char> rseen;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            if (seen.find(c) != seen.end() && seen[c] != w) return false;
            if (rseen.find(w) != rseen.end() && rseen[w] != c) return false;
            seen[c] = w;
            rseen[w] = c;
        }
        return true;
    }
};