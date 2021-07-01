// https://leetcode.com/problems/open-the-lock

#define uset unordered_set
#define v vector

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        uset<string> seen;
        for (auto& word: deadends) seen.insert(word);
        if (seen.find("0000") != seen.end()) return -1;
        seen.insert("0000");
        deque<pair<string, int>> dq;
        dq.push_back({"0000", 0});
        while (!dq.empty()) {
            auto node = dq.front();
            string w = node.first;
            if (w == target) return node.second;
            dq.pop_front();
            for (int i = 0; i < 4; i++) {
                string word(w.begin(), w.end());
                char a = ((w[i] - '0' + 1) % 10) + '0';
                char b = ((w[i] - '0' - 1 + 10) % 10) + '0';
                for (auto c: {a, b}) {
                    word[i] = c;
                    if (seen.find(word) == seen.end()) {
                        seen.insert(word);
                        dq.emplace_back(word, node.second + 1);
                    }
                }
            }
        }
        return -1;
    }
};