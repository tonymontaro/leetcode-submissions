// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int a[200] = {0};
        for (auto &w: words) {
            for (auto c: w) a[c]++;
        }
        int n = words.size();
        for (int i = 0; i < 200; i++) if (a[i] % n != 0) return false;
        return true;
    }
};