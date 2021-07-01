// https://leetcode.com/problems/perfect-number

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int i = 2; 
        int sm = 1;
        while (i * i <= num) {
            if (num % i == 0) {
                sm += i;
                int other = num / i;
                if (other != i ) sm += other;
            }
            i++;
        }
        return sm == num;
    }
};