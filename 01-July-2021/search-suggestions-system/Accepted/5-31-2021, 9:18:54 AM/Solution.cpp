// https://leetcode.com/problems/search-suggestions-system

class Trie {
public:
    map<char, Trie> c;
    vector<string> suggestions;
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
                if (node->c.find(c) == node->c.end()) node->c[c] = Trie();
                node = &node->c[c];
                if (node->suggestions.size() < 3) node->suggestions.push_back(word);
            }
        }

        vector<vector<string>> ans;
        Trie* node = root;
        bool done = false;
        for (char c: searchWord) {
            if (done || node->c.find(c) == node->c.end()) {
                done = true;
                ans.emplace_back(vector<string>());
                continue;
            }
            ans.push_back(node->c[c].suggestions);
            node = &node->c[c];
        }
        return ans;
    }
};