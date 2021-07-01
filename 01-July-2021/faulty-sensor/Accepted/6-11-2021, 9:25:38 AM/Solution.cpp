// https://leetcode.com/problems/faulty-sensor

class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        int n = sensor1.size();
        for (int i = 0; i < n; i++) {
            if (sensor1[i] == sensor2[i]) continue;
            bool a = true;
            for (int j = i; j < n - 1; j++) {
                if (sensor1[j] != sensor2[j + 1]) {
                    a = false;
                    break;
                }
            }
            bool b = true;
            for (int j = i; j < n - 1; j++) {
                if (sensor2[j] != sensor1[j + 1]) {
                    b = false;
                    break;
                }
            }
            if (a && b) return -1;
            return a ? 1 : 2;
        }
        return -1;
    }
};