// https://leetcode.com/problems/word-subsets

#define v vector


class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {

        int count[26] = {0};
        for (auto &x: B) {
            int cnt[26] = {0};
            for (int i = 0; i < x.size(); i++) {
                int ch = x[i] - 'a';
                cnt[ch]++;
                if (cnt[ch] > count[ch]) count[ch] = cnt[ch];
            } 
        }
        v<string> ans;
        ans.reserve(A.size());
        for (auto &word: A) {
            int cnt[26] = {0};
            for (int i = 0; i < word.size(); i++) cnt[word[i]-'a']++; 
            bool valid = true;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] < count[i]) {
                    valid = false;
                    break;
                }
            } 
            if (valid) ans.push_back(word);
        }
        return ans;
    }
};