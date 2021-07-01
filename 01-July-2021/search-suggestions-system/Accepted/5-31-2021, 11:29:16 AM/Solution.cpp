// https://leetcode.com/problems/search-suggestions-system

class Trie {
public:
    struct Trie* c[26];
    vector<string> suggestions;
    Trie() {
        for (auto & i : c) i = nullptr;
    }
};


class Solution {
public:
    Trie* root;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        root = new Trie();

        for (auto &word: products) {
            Trie* node = root;
            for (char c: word) {
                if (!node->c[c - 'a']) node->c[c - 'a'] = new Trie();
                node = node->c[c - 'a'];
                if (node->suggestions.size() < 3) node->suggestions.push_back(word);
            }
        }

        vector<vector<string>> ans;
        Trie* node = root;
        bool done = false;
        for (char c: searchWord) {
            if (done || !node->c[c - 'a']) {
                done = true;
                ans.emplace_back(vector<string>());
                continue;
            }
            node = node->c[c - 'a'];
            ans.push_back(node->suggestions);
        }
        return ans;
    }
};