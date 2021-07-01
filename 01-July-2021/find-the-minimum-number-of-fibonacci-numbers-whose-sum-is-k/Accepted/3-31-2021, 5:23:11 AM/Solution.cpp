// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k

#define v vector



class Solution {
public:
    v<int> fibs = {1};
    Solution() {
        int a = 1, b = 1;
        while (b <= 1e9) {
            int tmp = b;
            b = a + b;
            a = tmp;
            fibs.push_back(b);
        }
        reverse(fibs.begin(), fibs.end());
    }
    int findMinFibonacciNumbers(int k) {
        int ans = 0;
        for (int i = 0; i < fibs.size(); i++) {
            while (fibs[i] <= k) {
                ans++;
                k -= fibs[i];
            }
        } 
        return ans;
    }
};