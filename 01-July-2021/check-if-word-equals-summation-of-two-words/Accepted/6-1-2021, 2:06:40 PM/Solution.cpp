// https://leetcode.com/problems/check-if-word-equals-summation-of-two-words

class Solution {
public:
    bool isSumEqual(string a, string b, string t) {
        vector<int> hold;
        for (auto& x: {a, b, t}) {
            int val = 0;
            for (int i = 0; i < x.size(); ++i) val = val * 10 + (x[i] - 'a');
            hold.push_back(val);
        }
        return hold[0] + hold[1] == hold[2];
    }
};