// https://leetcode.com/problems/find-the-shortest-superstring

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector



class Solution {
public:
    umap<string, umap<string, int>> mp;
    string shortestSuperstring(vector<string>& words) {
        for (auto& w1: words) {
            for (auto& w2: words) overlap(w1, w2);
        }
        int n = words.size();
        int dp[1 << n][n];
        int parent[1 << n][n];
        memset(dp, 0, sizeof(dp));
        memset(parent, -1, sizeof(parent));

        for (int mask = 0; mask < (1 << n); mask++) {
            for (int bit = 0; bit < n; bit++) {
                int pmask = (1 << bit) ^ mask;
                if (((1 << bit) & mask) == 0 || pmask == 0) continue;
                for (int lastSetElement = 0; lastSetElement < n; lastSetElement++) {
                    if (((1 << lastSetElement) & pmask) == 0) continue;
                    int val = dp[pmask][lastSetElement] + overlap(words[lastSetElement], words[bit]);
                    if (val >= dp[mask][bit]) {
                        dp[mask][bit] = val;
                        parent[mask][bit] = lastSetElement;
                    }
                }
            }
        }
        vector<int> best;
        int mask = (1 << n) - 1;
        int node = 0;
        for (int i = 0; i < n; i++) if (dp[mask][i] > dp[mask][node]) node = i;

        best.push_back(node);
        while (mask != 0) {
            int p = parent[mask][node];
            if (p == -1) break;
            mask = (1 << node) ^ mask;
            node = p;
            best.push_back(node);
        }
        reverse(best.begin(), best.end());
        string ans = words[best[0]];
        for (int i = 1; i < n; i++) {
            int offset = overlap(words[best[i - 1]], words[best[i]]);
            ans += words[best[i]].substr(offset);
        }
        return ans;
    }
    int overlap(string a, string b) {
        if (mp.find(a) != mp.end() && mp[a].find(b) != mp[a].end()) return mp[a][b];
        for (int i = 0; i < a.size(); i++) {
            int j = i, z = 0;
            while (j < a.size() && a[j] == b[z]){
                j++; z++;
            }
            if (j == a.size()) {
                mp[a][b] = z;
                return z;
            }
        }
        mp[a][b] = 0;
        return 0;
    }
    int countBit(int num){
        int ans = 0;
        while (num > 0) {
            ans = ans + (num & 1);
            num >>= 1;
        }
        return ans;
    }
};


