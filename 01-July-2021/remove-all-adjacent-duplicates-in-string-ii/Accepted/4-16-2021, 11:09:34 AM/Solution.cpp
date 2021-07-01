// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> arr = {{' ', 0}};
        for (int i = 0; i < s.size(); i++) {
            int last = arr.size() - 1;
            if (arr[last].first != s[i])
                arr.push_back({s[i], 1});
            else if (arr[last].second + 1 == k)
                arr.pop_back();
            else 
                arr[last].second++;
        }
        string res = "";
        for (auto [ch, cnt]: arr) {
            for (int i = 0; i < cnt; i++) res += ch;
        }
        return res;
    }
};