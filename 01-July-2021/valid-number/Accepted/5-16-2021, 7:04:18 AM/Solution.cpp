// https://leetcode.com/problems/valid-number

class Solution {
public:
    int eloc = -1;
    bool isNumber(string s) {
        if (!noCharacters(s)) return false;
        if (eloc != -1) {
            if (eloc == 0 || eloc == s.size() - 1) return false;
            string a = s.substr(0, eloc);
            string b = s.substr(eloc + 1);
            return (isValidNumber(a) || isDecimal(a)) && isValidNumber(b);
        } else {
            return isValidNumber(s) || isDecimal(s);
        }

    }
    bool noCharacters(string &s) {
        int es = 0;
        for (int i = 0; i < s.size(); ++i) {
            char x = s[i];
            if (isdigit(x)) continue;
            x = tolower(x);
            if (x == 'e') { es++; eloc = i; }
            else if (x != '-' && x != '+' && x != '.') return false;
        }
        return es < 2;
    }
    bool isValidNumber(string s) {
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        if (s.size() == 0) return false;
        for (auto x: s) if (!isdigit(x)) return false;
        return true;
    }
    bool isDecimal(string s) {
        if (s[0] == '+' || s[0] == '-') s = s.substr(1);
        if (s.size() == 0 || (s.size() == 1 && s[0] == '.')) return false;
        int dec = -1;
        for (int i = 0; i < s.size(); i++) {
            char x = s[i];
            if (x == '.') {
                if (dec != -1) return false;
                dec = i;
            } else if (!isdigit(x)) return false;
        }
        return true;
    }
};