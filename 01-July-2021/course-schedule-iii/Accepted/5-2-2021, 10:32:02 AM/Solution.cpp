// https://leetcode.com/problems/course-schedule-iii

#define v vector

bool compare(v<int> &a, v<int> &b){
    return a[1] < b[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);
        priority_queue<int> pq;
        int total = 0;
        for (auto x: courses) {
            if (x[0] > x[1]) continue;
            if (total + x[0] <= x[1]) {
                pq.push(x[0]);
                total += x[0];
            } else if (pq.top() > x[0]) {
                total += (x[0] - pq.top());
                pq.pop();
                pq.push(x[0]);
            }
        }
        
        return pq.size();
    }
};