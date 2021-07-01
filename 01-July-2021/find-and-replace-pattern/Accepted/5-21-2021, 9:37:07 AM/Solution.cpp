// https://leetcode.com/problems/find-and-replace-pattern

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto &word: words) {
            map<char, char> seen;
            set<char> used;
            bool isValid = true;
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                if ((seen.find(ch) != seen.end() && seen[ch] != pattern[i])
                || (seen.find(ch) == seen.end() && used.find(pattern[i]) != used.end())
                ) {
                    isValid = false;
                    break;
                }
                seen[ch] = pattern[i];
                used.insert(pattern[i]);
            }
            if (isValid) ans.push_back(word);
        }
        return ans;
    }
};