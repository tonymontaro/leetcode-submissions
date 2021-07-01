// https://leetcode.com/problems/ambiguous-coordinates

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        s = s.substr(1, s.size() - 2);
        vector<string> result;

        for (int i = 1; i < s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);
            vector<string> leftVec;
            vector<string> rightVec;
            process(left, leftVec);
            process(right, rightVec);
            for (auto &l: leftVec) {
                for (auto &r: rightVec) {
                    result.emplace_back("(" + l + ", " + r + ")");
                }
            }
        }

        return result;
    }
    void process(string &s, vector<string> &result) {
        addNumber(s, result);
        addDecimals(s, result);
    }
    void addNumber(string &s, vector<string> &result) {
        if (s.size() > 1 && s[0] == '0') return;
        result.push_back(s);
    }
    void addDecimals(string &s, vector<string> &result) {
        if (s.size() == 1) return;
        if (s[s.size() - 1] == '0') return;
        if (s[0] == '0') {
            result.push_back("0." + s.substr(1));
            return;
        }
        for (int i = 1; i < s.size(); i++) {
            result.push_back(s.substr(0, i) + "." + s.substr(i));
        }
    }
};