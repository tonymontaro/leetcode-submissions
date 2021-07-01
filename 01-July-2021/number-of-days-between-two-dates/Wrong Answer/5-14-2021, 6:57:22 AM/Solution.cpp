// https://leetcode.com/problems/number-of-days-between-two-dates

class Solution {
public:
    int daysBetweenDates(string d1, string d2) {
        struct tm t1 = {0,0,0,stoi(d1.substr(8,2)),stoi(d1.substr(5,2)),stoi(d1.substr(0,4))};
        struct tm t2 = {0,0,0,stoi(d2.substr(8,2)),stoi(d2.substr(5,2)),stoi(d2.substr(0,4))};
        auto time1 = mktime(&t1);
        auto time2 = mktime(&t2);
        auto diff = abs(difftime(time2, time1));

        return diff / (60 * 60 * 24);
    }
};