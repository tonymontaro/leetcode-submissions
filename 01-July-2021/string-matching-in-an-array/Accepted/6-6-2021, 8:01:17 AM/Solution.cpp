// https://leetcode.com/problems/string-matching-in-an-array

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b) {
            if (b.size() < a.size()) return false;
            return a.size() < b.size();
        });
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i+1; j < words.size(); j++) {
                if (words[i].size() == words[j].size()) continue;
                int f = words[j].find(words[i]);
                if (f != -1) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};