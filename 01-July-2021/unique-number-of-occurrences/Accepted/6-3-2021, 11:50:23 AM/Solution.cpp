// https://leetcode.com/problems/unique-number-of-occurrences

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cnt;
        for (auto i: arr) cnt[i]++;
        set<int> seen;
        for(auto [k, v]: cnt) {
            if (seen.find(v) != seen.end()) return false;
            seen.insert(v);
        }
        return true;
    }
};