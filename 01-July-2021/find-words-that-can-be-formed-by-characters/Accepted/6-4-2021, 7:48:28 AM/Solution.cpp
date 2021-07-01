// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        auto source = countChars(chars);
        int ans = 0;
        for (auto& w: words) {
            auto dest = countChars(w);
            bool isValid = true;
            for (int i = 0; i < 26; i++) if (dest[i] > source[i]) {
                isValid = false;
                break;
            }
            if (isValid) ans += w.size();
        }
        return ans;
    }
    vector<int> countChars(string& s) {
        vector<int> cnt(26);
        for (auto c: s) cnt[c - 'a']++;
        return cnt;
    }
};