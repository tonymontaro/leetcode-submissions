// https://leetcode.com/problems/1-bit-and-2-bit-characters

#define uset unordered_set
class Solution {
public:
    uset<int> seen;
    bool isOneBitCharacter(vector<int>& bits) {
        return solve(0, bits);
    }
    bool solve(int i, vector<int>& bits) {
        if (i >= bits.size() || seen.find(i) != seen.end()) return false;
        if (i == bits.size()-1) return true;
        seen.insert(i);
        if (bits[i] == 1) return solve(i + 2, bits);
        return solve(i + 1, bits);
    }
};