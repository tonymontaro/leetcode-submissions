// https://leetcode.com/problems/groups-of-special-equivalent-strings


class Solution {
public:
    int even[20][26];
    int odd[20][26];
    int numSpecialEquivGroups(vector<string>& words) {
        memset(even, 0, sizeof(even));
        memset(odd, 0, sizeof(odd));
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                char c = words[i][j];
                if (j % 2 == 0) even[i][c - 'a']++;
                else odd[i][c - 'a']++;
            }
        }
        int seen[20] = {0}; int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            if (seen[i]) continue;
            ans++;
            for (int j = i + 1; j < words.size(); j++) {
                if (seen[j]) continue;
                if (isSame(words[i], words[j], i, j)) {
                    seen[j] = 1;
                }
            }
        }
        return ans;
    }
    bool isSame(string& a, string& b, int x, int y) {
        for (int i = 0; i < 26; i++) {
            if (even[x][i] != even[y][i]) return false;
            if (odd[x][i] != odd[y][i]) return false;
        }
        return true;
    }
};