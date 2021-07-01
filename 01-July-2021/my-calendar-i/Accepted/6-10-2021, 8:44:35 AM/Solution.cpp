// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    vector<pair<int, int>> seen;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto &x: seen) if (!(start >= x.second || end <= x.first)) return false;
        seen.emplace_back(start, end);
        return true;
    }
};