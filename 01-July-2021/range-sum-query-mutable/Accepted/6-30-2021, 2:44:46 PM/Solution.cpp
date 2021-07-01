// https://leetcode.com/problems/range-sum-query-mutable

class SegmentTree {
public:
    const int N = 1e5;  // limit for array size
    int n;  // array size
    int t[200000];
    void build() {  // build the tree
        for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
    }
    void modify(int p, int value) {  // set value at position p
        for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
    }
    int query(int l, int r) {  // sum on interval [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) res += t[l++];
            if (r&1) res += t[--r];
        }
        return res;
    }
    SegmentTree(vector<int> arr) {
        n = arr.size();
        for (int i = 0; i < n; ++i) t[n + i] = arr[i];
        build();
    }
};

class NumArray {
public:
    SegmentTree* seg;
    NumArray(vector<int>& nums) {
        seg = new SegmentTree(nums);
    }

    void update(int index, int val) {
        seg->modify(index, val);
    }

    int sumRange(int left, int right) {
        return seg->query(left, right + 1);
    }
};