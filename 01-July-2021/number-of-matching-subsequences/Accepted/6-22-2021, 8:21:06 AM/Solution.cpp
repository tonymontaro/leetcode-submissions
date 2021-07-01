// https://leetcode.com/problems/number-of-matching-subsequences

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        v<v<int>> alp(130, v<int>());
        for (int i = 0; i < s.size(); i++) {
            alp[s[i]].push_back(i);
        } 
        int ans = 0;
        for (auto& w: words) {
            bool isValid = true;
            int start = 0;
            for (auto c: w) {
                start = find(start, c, alp);
                if (start == -1) {
                    isValid = false;
                    break;
                }
                start++;
            }
            if (isValid) ans++;
        }
        return ans;
    }
    
    int find(int start, char c, v<v<int>> &alp) {
        int ans = -1;
        int lo = 0, hi = alp[c].size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if (alp[c][mid] >= start) {
                ans = alp[c][mid];
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};