// https://leetcode.com/problems/verifying-an-alien-dictionary

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int topo[26];
        for (int i = 0; i < order.size(); i++) topo[order[i] - 'a'] = i;
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i];
            string b = words[i+1];
            int diff = 0;
            for (int j = 0; j < min(a.size(), b.size()); j++) {
                if (a[j] == b[j]) continue;
                diff = topo[b[j] - 'a'] - topo[a[j] - 'a'];
                break;
            }

            if (diff < 0 || (diff == 0 && b.size() < a.size()))
                return false;
        }
        return true;
    }
};