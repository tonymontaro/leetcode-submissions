// https://leetcode.com/problems/number-of-days-in-a-month

class Solution {
public:
    int numberOfDays(int y, int m) {
        int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        bool isLeapYear = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (isLeapYear) months[1] = 29;
        return months[m-1];
    }
};