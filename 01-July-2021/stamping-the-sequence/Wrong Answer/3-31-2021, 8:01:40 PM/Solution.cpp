// https://leetcode.com/problems/stamping-the-sequence

#define v vector

class Solution {
public:
    string stamp, target;
    vector<int> movesToStamp(string stamp1, string target1) {
        stamp = std::move(stamp1), target = std::move(target1);
        v<int> ans;
        int seen[1000] = {0};
        int n = target.size(), m = stamp.size();
        while (true) {
            int sta = -1;
            for (int i = 0; i < n - m + 1; i++) {
                if (seen[i] == 1) continue;
                if (check(i)) {
                    sta = i;
                    break;
                }
            }
            if (sta == -1) break;
            for (int i = sta; i < sta + m; i++) {
                target[i] = '?';
            }
            seen[sta] = 1;
            ans.push_back(sta);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool check(int start) {
        bool notallque = false;
        for (int i = start; i < start + stamp.size(); i++) {
            int si = i - start;
            if (target[i] == stamp[si]) notallque = true;
            if (target[i] != stamp[si] && target[i] != '?') return false;
        }

        return notallque;
    }
};