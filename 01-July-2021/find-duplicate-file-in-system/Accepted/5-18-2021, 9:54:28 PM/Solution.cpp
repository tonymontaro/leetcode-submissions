// https://leetcode.com/problems/find-duplicate-file-in-system

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
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        umap<string, vector<string>> mp;
        for (auto path: paths) {
            auto files = splitWord(path);
            string root = files[0];
            for (int i = 1; i < files.size(); i++) {
                int start = files[i].find('(');
                string filepath = root + "/" + files[i].substr(0, start);
                mp[files[i].substr(start + 1)].push_back(filepath);
            }
        }
        vector<vector<string>> ans;
        for (auto [k, v]: mp) {
            if (v.size() > 1) ans.push_back(v);
        }
        return ans;
    }
};