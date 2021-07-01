// https://leetcode.com/problems/best-team-with-no-conflicts

class Solution {
public:
int bestTeamScore(vector<int>& scores, vector<int>& ages) {

    vector<vector<int>> vc;
    int n = scores.size();
    for (int i = 0; i < n; i++) {
        vc.push_back({ages[i], scores[i]});
    }
    sort(vc.begin(), vc.end());

    vector<int> dp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = vc[i][1];
        for (int j = 0; j < i; j++) {
            if (vc[i][1] >= vc[j][1])
                dp[i] = max(dp[i], dp[j] + vc[i][1]);
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}
};