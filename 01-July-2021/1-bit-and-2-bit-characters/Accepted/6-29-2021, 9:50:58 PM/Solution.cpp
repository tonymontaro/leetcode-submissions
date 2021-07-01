// https://leetcode.com/problems/1-bit-and-2-bit-characters

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size()) {
            if (i == bits.size()-1) return true;
            if (bits[i]) i += 2;
            else i++;
        }
        return false;
    }
};