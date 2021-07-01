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
            int res = 1;
            for (int j = 0; j < i; j++) {
                int xx = envelopes[j][0], yy = envelopes[j][1];
                if (xx < x && yy < y) 
                    res = max(res, 1 + ans[j]);
            } 
            ans[i] = res;
            answer = max(answer, res);
        }

        return answer;
    }
};