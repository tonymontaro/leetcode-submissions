// https://leetcode.com/problems/before-and-after-puzzle

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector




class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string> phrases) {
        map<int, pair<string, string>> mp;
        for (int i = 0; i < phrases.size(); i++) {
            string s = phrases[i];
            int first = s.find(' ');
            int last = s.rfind(' ');
            mp[i] = {s.substr(0, first), s.substr(last + 1)};
        }
        set<string> ans;
        for (int i = 0; i < phrases.size(); i++) {
            for (int j = 0; j < phrases.size(); j++) {
                if (i == j || mp[i].second != mp[j].first) continue;
                int sz = mp[j].first.size();
                ans.insert((phrases[i] + phrases[j].substr(sz)));
            }
        }
        v<string> aa(ans.begin(), ans.end());
        return aa;
    }
};
