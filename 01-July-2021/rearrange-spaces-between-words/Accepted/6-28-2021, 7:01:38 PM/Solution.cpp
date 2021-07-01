// https://leetcode.com/problems/rearrange-spaces-between-words

class Solution {
public:
    string reorderSpaces(string text) {
        int spaces = 0, i = 0;
        vector<string> words;
        while (i < text.size()) {
            if (text[i] == ' ') {
                spaces++; i++; continue;
            }
            string w = "";
            while (i < text.size() && text[i] != ' ') w += text[i++];
            words.push_back(w);
        }
        if (words.size() == 1) {
            string la(spaces, ' ');
            return words[0] + la;
        }
        int sepLen = spaces / (words.size() - 1);
        string sep(sepLen, ' ');
        string ans = "";
        for (int i = 0; i < words.size() - 1; i++) ans += words[i] + sep;
        ans += words[words.size() - 1];
        string last(spaces - sepLen * (words.size() - 1), ' ');
        ans += last;
        return ans;
    }
};