// https://leetcode.com/problems/find-smallest-letter-greater-than-target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char low = ' ', hi = ' ';
        for (auto c: letters) {
            if (low == ' ' || c < low) low = c;
            if (c > target && (hi == ' ' || c < hi)) hi = c;
        }
        return hi == ' ' ? low : hi;
    }
};