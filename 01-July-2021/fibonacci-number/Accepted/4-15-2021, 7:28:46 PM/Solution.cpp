// https://leetcode.com/problems/fibonacci-number

#define ll long long

class Solution {
public:
    ll cache[31];
    Solution(){
        cache[0] = 0;
        cache[1] = 1;
        for (int i = 2; i < 31; i++) cache[i] = cache[i - 1] + cache[i - 2];
    }
    int fib(int n) {
        return cache[n];
    }
};