// https://leetcode.com/problems/convert-a-number-to-hexadecimal

class Solution {
public:
    string toHex(int num) {
        std::stringstream stream;
        stream << std::hex << num;
        return stream.str();
    }
};