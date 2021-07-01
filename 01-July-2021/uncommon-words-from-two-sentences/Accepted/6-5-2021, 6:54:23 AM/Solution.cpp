// https://leetcode.com/problems/uncommon-words-from-two-sentences

vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        auto w1 = splitWord(s1);
        auto w2 = splitWord(s2);
        map<string, int> cnt;
        for (auto &x: w2) cnt[x]++;
        for (auto &x: w1) cnt[x]++;
        vector<string> ans;
        for (auto [k, v]: cnt) if (v == 1) ans.push_back(k);
        return ans;
    }
};