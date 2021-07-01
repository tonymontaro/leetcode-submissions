// https://leetcode.com/problems/relative-ranks

#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        v<int> vc(n);
        for (int i = 0; i < n; i++) vc[i] = i;
        sort(vc.begin(), vc.end(), [&score](int a, int b){
            if (score[b] > score[a]) return false;
            return score[a] > score[b];
        });
        v<string> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) ans[vc[i]] = "Gold Medal";
            else if (i == 1) ans[vc[i]] = "Silver Medal";
            else if (i == 2) ans[vc[i]] = "Bronze Medal";
            else ans[vc[i]] = (to_string(i + 1));
        }
        return ans;
    }
};