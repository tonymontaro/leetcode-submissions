// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

#define v vector

string join(const vector<char> &lst, const string &delim) {
    string ret;
    for(const auto &s : lst) {
        if(!ret.empty())
            ret += delim;
        ret += s;
    }
    return ret;
}

class Solution {
public:
    int n, k;
    string ans = "";
    string st = "abc";
    int cnt = 0;
    string getHappyString(int nn, int kk) {
        n = nn, k = kk;
        v<char> arr;
        solve(0, arr, '*');
        return ans;
    }
    void solve(int idx, v<char> &arr, char prev) {
        if (cnt >= k) return;
        if (idx >= n) {
            cnt++;
            if (cnt == k)
                ans = join(arr, "");
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (st[i] == prev) continue;
            arr.push_back(st[i]);
            solve(idx + 1, arr, st[i]);
            arr.pop_back();
        } 
    }
};