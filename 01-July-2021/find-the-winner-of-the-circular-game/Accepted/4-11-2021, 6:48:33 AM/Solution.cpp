// https://leetcode.com/problems/find-the-winner-of-the-circular-game

#define v vector




class Solution {
public:
    int findTheWinner(int n, int k) {
        int idx = 0;
        v<int> arr;
        for (int i = 0; i < n; i++) arr.push_back(i + 1);
        while (n > 1) {
            int remove = (idx + k - 1) % n;
            arr.erase(arr.begin() + remove);
            n--;
            idx = remove % n;
        }
        return arr[0];
    }
};