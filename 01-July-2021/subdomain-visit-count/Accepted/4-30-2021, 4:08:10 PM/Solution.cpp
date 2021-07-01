// https://leetcode.com/problems/subdomain-visit-count

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector

vector<string> splitWord(string &text) {
    istringstream iss(text);
    vector<string> results((istream_iterator<string>(iss)), istream_iterator<string>());
    return results;
}



class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, ll> ans;
        for (auto s: cpdomains) {
            auto vec = splitWord(s);
            int count = stoi(vec[0]);
            auto word = vec[1];
            ans[word] += count;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == '.')
                    ans[word.substr(i + 1)] += count;
            }
        }
        vector<string> result;
        for (auto [s, num]: ans) {
            result.push_back(to_string(num) + " " + s);
        }
        return result;
    }
};