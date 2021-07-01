// https://leetcode.com/problems/my-calendar-i

class MyCalendar {
public:
    set<int> seen;
    map<int, int> ends;
    MyCalendar() {
    }
    bool book(int start, int end) {
        auto it = lower_bound(seen.begin(), seen.end(), start);
        if (it != seen.end() && *it < end) return false;
        if (it != seen.begin()) {
            it--;
            if (ends[*it] > start) return false;
        }
        seen.insert(start);
        ends[start] = end;
        return true;
    }
};