// https://leetcode.com/problems/defanging-an-ip-address

class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for (auto c: address) {
            if (c == '.') ans += "[.]";
            else ans += c;
        }
        return ans;
    }
};