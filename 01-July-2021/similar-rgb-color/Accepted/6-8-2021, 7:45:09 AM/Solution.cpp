// https://leetcode.com/problems/similar-rgb-color

int hexToDec(string s) {
    int y;
    stringstream stream(s);
    stream >> hex >> y;
    return y;
}

class Solution {
public:
    vector<string> validAlphas = {
            "00", "11", "22", "33", "44", "55", "66", "77", "88", "99", "aa", "bb", "cc", "dd", "ee", "ff"
    };
    vector<int> validToDec;
    Solution() {
        for (int i = 0; i < validAlphas.size(); i++) validToDec.push_back(hexToDec(validAlphas[i]));
    }
    string similarRGB(string& color) {
        string ans = "#";
        ans += bestHex(hexToDec(color.substr(1, 2)));
        ans += bestHex(hexToDec(color.substr(3, 2)));
        ans += bestHex(hexToDec(color.substr(5, 2)));
        return ans;
    }
    string bestHex(int num) {
        int best = 0;
        for (int i = 0; i < validToDec.size(); i++)
            if (abs(num - validToDec[i]) < abs(num - validToDec[best])) best = i;
        return validAlphas[best];
    }
};