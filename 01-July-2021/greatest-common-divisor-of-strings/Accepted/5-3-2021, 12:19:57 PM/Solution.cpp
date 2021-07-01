// https://leetcode.com/problems/greatest-common-divisor-of-strings


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int gd = gcd(n, m);
        string ans = "";
        for (int i = 1; i < gd + 1; i++) {
            if (gd % i != 0) continue;
            string s = str1.substr(0, i);
            if (valid(s, str1) && valid(s, str2)) ans = s;
        } 
        return ans;
    }
    bool valid(string &s, string &ss) {
        string compare = "";
        while (compare.size() < ss.size()) compare += s;
        return compare == ss;
    }
};