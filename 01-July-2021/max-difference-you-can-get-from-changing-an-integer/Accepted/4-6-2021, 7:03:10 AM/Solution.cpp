// https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        char rep = '9';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != rep) {
                rep = s[i];
                break;
            }
        }
        int a = replace(s, rep, '9');
        
        bool allOne = true;
        for (int i = 0; i < s.size(); i++) if (s[i] != '1') {
            allOne = false;
                break;
        }
        if (allOne) return a - num;
        
        char rp = (s[0] == '1') ? '0' : '1';
        rep = '0';
        bool firstOne = s[0] == '1';
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && firstOne) continue;
            if (s[i] != rp) {
                rep = s[i];
                break;
            }
        }
        int b = replace(s, rep, rp);
        return a - b;
    }
    int replace(string s, char rep, char dest) {
        for (int i = 0; i < s.size(); i++) if (s[i] == rep) s[i] = dest;
        int ans = 0;
        stringstream ss(s);
        ss >> ans;
        return ans;
    }
};