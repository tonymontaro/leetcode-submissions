// https://leetcode.com/problems/reformat-the-string

class Solution {
public:
    string reformat(string s) {
        string ans;
        string aa;
        string bb;
        for (auto x: s) if (isalpha(x))
                aa.push_back(x);
            else
                bb.push_back(x);
        int diff = aa.size() - bb.size();
        if (abs(diff) > 1) return "";
        int i = 0, j = 0, mx = max(aa.size(), bb.size());
        if (bb.size() > aa.size()) swap(aa, bb);
        for (int k = 0; k < mx; ++k) {
            if (i < aa.size()) ans += aa[i++];
            if (j < bb.size()) ans += bb[j++];
        }
        return ans;
    }
};