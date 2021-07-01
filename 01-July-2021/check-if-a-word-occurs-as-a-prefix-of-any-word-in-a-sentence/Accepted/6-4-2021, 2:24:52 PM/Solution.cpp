// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto words = splitWord(sentence);
        for (int i = 0; i < words.size(); i++)  {
            if (isprefix(words[i], searchWord)) return i + 1;
        }
        return -1;
    }
    bool isprefix(string& a, string& b) {
        if (b.size() > a.size()) return false;
        for (int i = 0; i < b.size(); i++) if (b[i] != a[i]) return false;
        return true;
    }
};