// https://leetcode.com/problems/palindrome-pairs

class Trie {
public:
    struct Trie* c[300];
    vector<int> ends;
    Trie() {
        for (auto & i : c) i = nullptr;
    }
};


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<bool>> forward;
        vector<vector<bool>> backward;
        Trie *root = new Trie;
        Trie *rootB = new Trie;
        for (int idx = 0; idx < words.size(); ++idx) {
            string word = words[idx];
            int n = word.size();
            vector<bool> forw(n);
            vector<bool> backw(n);
            Trie* node = root;
            Trie* nodeB = rootB;
            for (int i = 0; i < n; i++) {
                char c = word[n - i - 1];
                forw[i] = isPal(i + 1, n - 1, word);
                backw[i] = isPal(0, i - 1, word);
                if (!node->c[c]) node->c[c] = new Trie();
                node = node->c[c];
                c = word[i];
                if (!nodeB->c[c]) nodeB->c[c] = new Trie();
                nodeB = nodeB->c[c];
            }
            node->ends.push_back(idx);
            nodeB->ends.push_back(idx);
            forward.push_back(forw);
            backward.push_back(backw);
        }


        set<pair<int, int>> ans;
        for (int idx = 0; idx < words.size(); ++idx) {
            string word = words[idx];
            if (word.empty()) {
                for (int i = 0; i < words.size(); i++) {
                    if (i == idx || !isPal(0, words[i].size()-1, words[i])) continue;
                    ans.insert({i, idx});
                    ans.insert({idx, i});
                }
                continue;
            }
            int n = word.size();
            Trie* node = root;
            for (int i = 0; i < n; i++) {
                char c = word[i];
                if (!node->c[c]) break;
                node = node->c[c];
                if (!forward[idx][i]) continue;
                for (auto secondIdx: node->ends) if (secondIdx != idx) ans.insert({idx, secondIdx});
            }
            node = rootB;
            for (int i = n - 1; i >= 0; --i) {
                char c = word[i];
                if (!node->c[c]) break;
                node = node->c[c];

                if (!backward[idx][i]) continue;
                for (auto firstIdx: node->ends) if (firstIdx != idx) ans.insert({firstIdx, idx});
            }
        }
        vector<vector<int>> res;
        for (auto& x: ans) res.push_back({x.first, x.second});
        return res;
    }

    bool isPal(int l, int r, string& s) {
        if (l >= r) return true;
        while (l <= r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
};