// https://leetcode.com/problems/di-string-match

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        ans.reserve(s.size());
        int left = 0, right = s.size();
        for (auto& c: s) {
            if (c == 'I') ans.push_back(left++);
            else ans.push_back(right--);
        }
        ans.push_back(left);
        return ans;
    }
};