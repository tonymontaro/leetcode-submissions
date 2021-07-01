// https://leetcode.com/problems/sorting-the-sentence

vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}

class Solution {
public:
    string sortSentence(string s) {
        map<int, string> seen;
        auto words = splitWord(s);
        for (const auto &w: words) {
            seen[w[w.size() - 1] - '0'] = w.substr(0, w.size() - 1);
        }
        string ans = "";
        for (int i = 0; i < seen.size(); i++) ans += seen[i+1] + " ";
        return ans.substr(0, ans.size() - 1);
    }
};