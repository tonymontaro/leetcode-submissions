// https://leetcode.com/problems/shortest-completing-word

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string lic = "";
        for (auto x: licensePlate) if (isalpha(x)) lic += tolower(x);
        vector<int> source(26);
        count(lic, source);
        vector<int> dest(26);
        string res = "";
        for (auto word: words) {
            count(word, dest);
            bool isValid = true;
            for (int i = 0; i < 26; i++) if (source[i] > dest[i]) {
                isValid = false; break;
            }
            if (isValid && (res.empty() || word.length() < res.length())) res = word;
        }
        return res;
    }
    void count(string s, vector<int>& cnt) {
        fill(cnt.begin(), cnt.end(), 0);
        for (auto x: s) cnt[x - 'a']++;
    }
};