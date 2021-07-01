// https://leetcode.com/problems/goat-latin

vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}

class Solution {
public:
    string toGoatLatin(string sentence) {
        string last = "a";
        auto words = splitWord(sentence);
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        string result = "";
        for (auto& w: words) {
            char f = tolower(w[0]);
            string ans = w;
            if (vowels.find(f) == vowels.end()) ans = ans.substr(1) + w[0];
            ans += "ma";
            ans += last;
            result += ans + " ";
            last += 'a';
        }
        return result.substr(0, result.size() - 1);
    }
};