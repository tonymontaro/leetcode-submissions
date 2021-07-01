// https://leetcode.com/problems/prefix-and-suffix-search

string delim = " ";
#define print(x) cout << x << endl
#define print2(x, y) cout << x << delim << y << endl

#define v vector

class TrieNode {
public:
    map<char, TrieNode> children;
    int wordIdx = -1;
};

class WordFilter {
public:
    TrieNode root;
    WordFilter(vector<string>& wordList) {
        int wordIdx = -1;
        for (auto word: wordList) {
            wordIdx++;
            v<string> words;
            string suffixPrefix = "#" + word;
            for (int i = word.size() - 1; i >= 0; --i) {
                suffixPrefix = word[i] + suffixPrefix;
                words.push_back(suffixPrefix);
            }
            for (auto w: words) {
                auto *node = &root;
                for (int i = 0; i < w.size(); i++) {
                    if (node->children.find(w[i]) == node->children.end()) {
                        node->children[w[i]] = TrieNode();
                    }
                    node = &node->children[w[i]];
                    node->wordIdx = wordIdx;
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string word = suffix + "#" + prefix;
        auto *node = &root;
        for (int i = 0; i < word.size(); i++) {
            if (node->children.find(word[i]) == node->children.end()) return -1;
            node = &node->children[word[i]];
        } 
        return node->wordIdx;
    }
};
