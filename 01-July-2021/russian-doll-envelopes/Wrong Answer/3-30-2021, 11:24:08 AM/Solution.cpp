// https://leetcode.com/problems/russian-doll-envelopes

#define v vector

int ans[5000] = {0};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        int answer = 0;
        for (int i = 0; i < n; i++) {
            int x = envelopes[i][0], y = envelopes[i][1];
            int lo = 0, hi = i - 1;
            int res = 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int xx = envelopes[mid][0], yy = envelopes[mid][1];
                if (xx < x && yy < y) {
                    res = max(res, 1 + ans[mid]);
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans[i] = res;
            answer = max(answer, res);
        }

        return answer;
    }
};