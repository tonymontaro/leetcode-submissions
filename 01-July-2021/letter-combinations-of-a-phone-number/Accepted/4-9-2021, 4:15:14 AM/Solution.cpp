// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        map<char, string> mp = {
                {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
                {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans = {""};
        for (int i = 0; i < digits.size(); i++) {
            char c = digits[i];
            vector<string> res;
            string keys = mp[c];
            for (int j = 0; j < keys.size(); j++)
                for (auto s: ans)
                    res.push_back(s + keys[j]);
            ans = res;    
        }
        return ans;
    }
};