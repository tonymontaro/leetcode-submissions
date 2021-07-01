// https://leetcode.com/problems/hexspeak

class Solution {
public:
    string toHexspeak(string num) {
        stringstream stream;
        stream << hex << stol(num);
        string res = stream.str();
        for (char& i: res) {
            if (isalpha(i)) {
                i = toupper(i);
                continue;
            }
            if (i == '0') i = 'O';
            else if (i == '1') i = 'I';
            else return "ERROR";
        }
        return res;
    }
};