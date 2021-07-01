// https://leetcode.com/problems/meeting-scheduler

class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& va, vector<vector<int>>& vb, int duration) {

        int a = 0, b = 0;
        while (a < va.size() && b < vb.size()) {
            while (b < vb.size() && vb[b][1] < va[a][0]) b++;
            if (b >= vb.size()) return {};
            while (a < va.size() && va[a][1] < vb[b][0]) a++;
            if (a >= va.size()) return {};
            int start = max(va[a][0], vb[b][0]);
            int end = start + duration;
            if (end <= va[a][1] && end <= vb[b][1]) return {start, end};
            else {
                if (va[a][0] > vb[b][0]) b++;
                else a++;
            }
        }

        return {};
    }
};