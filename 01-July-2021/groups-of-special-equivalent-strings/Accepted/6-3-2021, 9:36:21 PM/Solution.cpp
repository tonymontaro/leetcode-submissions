// https://leetcode.com/problems/groups-of-special-equivalent-strings

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        set<string> seen;
        for (auto& s: words) {
            string even;
            string odd;
            for (int i = 0; i < s.size(); i++) {
                if (i % 2 == 0) even += s[i];
                else odd += s[i];
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            seen.insert(even + odd);
        }
        return seen.size();
    }
};
