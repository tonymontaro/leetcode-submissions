// https://leetcode.com/problems/best-team-with-no-conflicts

class Solution {
public:
int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    vector<pair<int, int>> vc;
    int n = scores.size();
    for (int i = 0; i < n; i++) {
        vc.push_back(make_pair(ages[i], scores[i]));
    }
    sort(vc.begin(), vc.end());

    vector<int> dp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = vc[i].second;
        for (int j = 0; j < i; j++) {
            if (vc[i].second >= vc[j].second)
                dp[i] = max(dp[i], dp[j] + vc[i].second);
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}
};