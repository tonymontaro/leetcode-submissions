// https://leetcode.com/problems/rank-teams-by-votes

#define v vector


int cnt[27][27];
int seen[27];

bool compare(char &aa, char &bb) {
    int a = aa - 'A', b = bb - 'A';
    for (int i = 0; i < 27; i++) {
        if (cnt[i][a] > cnt[i][b]) {
            return true;
        } else if (cnt[i][b] > cnt[i][a]) {
            return false;
        }
    }
//    print2(aa, bb)
    return a < b;
}


class Solution {
public:
    string rankTeams(vector<string>& votes) {
        memset(cnt, 0, sizeof(cnt));
        memset(seen, 0, sizeof(seen));

        for (int i = 0; i < votes.size(); i++) {
            string s = votes[i];
            for (int j = 0; j < s.size(); j++) {
                cnt[j][s[j] - 'A']++;
                seen[s[j] - 'A'] = 1;
            }
        }
        string abcde = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string abcd = "";
        for (int i = 0; i < abcde.size(); i++) if (seen[abcde[i] - 'A'])
                abcd += abcde[i];
//        print(abcd)
        sort(abcd.begin(), abcd.end(), compare);
        return abcd;
    }
};
