// https://leetcode.com/problems/minimum-sideway-jumps

#define v vector

int minArr(vector<int>& arr){
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++) ans = min(ans, arr[i]);
    return ans;
}


class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int mx = 1000000;
        v<int> prev = {mx, 0, mx};
        for (int i = 0; i < obstacles.size(); i++) {
            v<int> arr = {mx, mx, mx};
            for (int j = 0; j < 3; j++) {
                if (obstacles[i] == j + 1) continue;
                for (int k = 0; k < 3; k++) {
                    if (obstacles[i] == k + 1) continue;
                    if (j == k) arr[j] = min(arr[j], prev[k]);
                    else arr[j] = min(arr[j], 1 + prev[k]);
                }
            }
            prev = arr;
        }
        return minArr(prev);
    }
};