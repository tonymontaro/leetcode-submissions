// https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n

#define v vector

int seen[1000000];
class Solution {
public:
    bool queryString(string s, int k) {
        if (k > 1000000) return false;
        memset(seen, 0, sizeof(seen));
        v<int> arr;
        arr.reserve(s.size());
        for (int i = 0; i < s.size(); i++) arr.push_back(s[i] - '0');
        for (int i = 0; i < s.size(); i++) {
            if (arr[i] == 0 ) continue;
            int num = 0;
            for (int j = i; j < s.size(); j++) {
                num += arr[j];
                if (num > k) break;
                seen[num]++;
                num = num << 1;
            }
        }
        for (int i = 1; i < k + 1; i++) {
            if (seen[i] == 0) return false;
        } 
        return true;
    }
};