// https://leetcode.com/problems/count-of-smaller-numbers-after-self

#define umap unordered_map
#define uset unordered_set
#define pi pair<ll, ll>
#define pii pair<ll, pi>
#define v vector
#define ll long long

class FenwickTree {
    // One indexed FenwickTree (Binary Indexed Tree)
public:
    FenwickTree(int nn) : n(nn), data(nn + 1) {}
    FenwickTree(int nn, v<ll> dat) : n(nn), data(nn + 1) {
        assert(nn == dat.size());
        for (int i = 1; i < n + 1; i++) {
            data[i] += dat[i - 1];
            int parent = i + (i & -i);
            if (parent <= n)
                data[parent] += data[i];
        }
    }

    void add(int i, ll val) {
        assert(i > 0 && i <= n);
        while (i <= n) {
            data[i] += val;
            i += (i & -i);
        }
    }
    ll sum(int left, int right) {
        // inclusive sum from left to right
        assert(left > 0 && left <= right && right <= n);
        return sum(right) - sum(left - 1);
    }
    ll sum(int i) {
        assert(i >= 0 && i <= n);
        ll ans = 0;
        while (i > 0) {
            ans += data[i];
            i -= (i & -i);
        }
        return ans;
    }

private:
    int n;
    vector<ll> data;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // compress array
        set<int> seen;
        for (auto x: nums) seen.insert(x);
        umap<int, int> mp;
        int idx = 1;
        for (auto x: seen) mp[x] = idx++;
        FenwickTree fen(idx);
        v<int> ans(nums.size());
        for (int i = nums.size() - 1; i >= 0; --i) {
            int midx = mp[nums[i]];
            ans[i] = fen.sum(midx - 1);
            fen.add(midx, 1);
        }
        return ans;
    }
};
