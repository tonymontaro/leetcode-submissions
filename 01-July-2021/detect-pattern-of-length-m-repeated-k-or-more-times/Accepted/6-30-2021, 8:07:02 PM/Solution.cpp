// https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int prod = m * k, n = arr.size();
        for (int i = 0; i < arr.size(); i++) {
            if (i + prod > n) break;
            int idx = i;
            bool isvalid = true;
            string prev = "", s = "";
            for (int j = 0; j < k; j++) {
                for (int l = 0; l < m; l++) s += (to_string(arr[idx++]) + ",");
                // cout << s << endl;
                if (!prev.empty() && prev != s) {
                    isvalid = false; break;
                }
                prev = s; s = "";
            }
            // cout << i << endl;
            if (isvalid) return true;
        }
        return false;
    }
};