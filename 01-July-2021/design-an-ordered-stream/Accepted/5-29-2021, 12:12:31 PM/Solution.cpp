// https://leetcode.com/problems/design-an-ordered-stream

class OrderedStream {
public:
    vector<string> res;
    int head = 0;
    int n;
    OrderedStream(int nn) {
        n = nn;
        res = vector<string>(n);
    }

    vector<string> insert(int idKey, string value) {
        res[idKey - 1] = value;
        vector<string> ans;
        while (head < n && !res[head].empty())
            ans.push_back(res[head++]);
        return ans;
    }
};