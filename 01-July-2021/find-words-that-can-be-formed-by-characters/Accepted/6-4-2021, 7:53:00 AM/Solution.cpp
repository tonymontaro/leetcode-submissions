// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> source(26);
        vector<int> dest(26);
        for (auto c: chars) source[c - 'a']++;
        int ans = 0;
        for (auto& w: words) {
            for (auto c: w) dest[c - 'a']++;
            bool isValid = true;
            for (int i = 0; i < 26; i++) {
                if (dest[i] > source[i]) isValid = false;
                dest[i] = 0;
            }
            if (isValid) ans += w.size();
        }
        return ans;
    }

    Solution() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};