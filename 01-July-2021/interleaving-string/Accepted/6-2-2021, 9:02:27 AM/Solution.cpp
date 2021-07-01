// https://leetcode.com/problems/interleaving-string

class Solution {
public:
    string a, b, c;
    int seen[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        a = s1; b = s2; c = s3;
        memset(seen, 0, sizeof(seen));
        return helper(0, 0, 0);
    }

    bool helper(int i, int j, int x) {
        if (seen[i][j]) return false;
        seen[i][j] = 1;
        if (i >= a.size() && j >= b.size()) return true;
        if (i < a.size() && a[i] == c[x] && helper(i + 1, j, x + 1)) return true;
        if (j < b.size() && b[j] == c[x] && helper(i, j + 1, x + 1)) return true;
        return false;
    }
};