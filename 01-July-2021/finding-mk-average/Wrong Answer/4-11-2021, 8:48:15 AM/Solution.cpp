// https://leetcode.com/problems/finding-mk-average


#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector


class MinHeap {
public:
    priority_queue<pi, v<pi>> pq;
    priority_queue<pi, v<pi>, greater<>> pall;
    int seen[100001];
    ll total = 0;
    int k, m;
    int cnt = 0;
    void init(int kk, int mm) {
        k = kk, m = mm;
        memset(seen, 0, sizeof(seen));
    }
    void add(int num, int idx) {
        if (cnt >= k) {
            if (pq.top().first > num)
                poptop();
            else {
                pall.push({num, idx});
                return;
            }
        }
        cnt++;
        pq.push({num, idx});
        seen[idx] = 1;
        total += num;
    }
    void poptop() {
        auto x = pq.top();
        seen[x.second] = 0;
        total -= x.first;
        pall.push(x);
        pq.pop();
        while (seen[pq.top().second] == -1)
            pq.pop();
        while (!pall.empty() && seen[pall.top().second] == -1)
            pall.pop();
    }
    void remove(int num, int idx) {
        int prev = seen[idx];
        seen[idx] = -1;
        while (!pall.empty() && seen[pall.top().second] == -1)
            pall.pop();
        if (prev == 1) {
            total -= num;
            auto nxt = pall.top();
            seen[nxt.second] = 1;
            pall.pop();
            pq.push(nxt);
            total += nxt.first;
        }
        while (seen[pq.top().second] == -1)
            pq.pop();
    }
};

class MaxHeap {
public:
    priority_queue<pi, v<pi>, greater<>> pq;
    priority_queue<pi, v<pi>> pall;
    int seen[100001];
    ll total = 0;
    int k, m;
    int cnt = 0;
    void init(int kk, int mm) {
        k = kk, m = mm;
        memset(seen, 0, sizeof(seen));
    }
    void add(int num, int idx) {
        if (cnt >= k) {
            if (pq.top().first < num)
                poptop();
            else {
                pall.push({num, idx});
                return;
            }
        }
        cnt++;
        pq.push({num, idx});
        seen[idx] = 1;
        total += num;
    }
    void poptop() {
        auto x = pq.top();
        seen[x.second] = 0;
        total -= x.first;
        pall.push(x);
        pq.pop();
        while (seen[pq.top().second] == -1)
            pq.pop();
        while (!pall.empty() && seen[pall.top().second] == -1)
            pall.pop();
    }
    void remove(int num, int idx) {
        int prev = seen[idx];
        seen[idx] = -1;
        while (!pall.empty() && seen[pall.top().second] == -1)
            pall.pop();
        if (prev == 1) {
            total -= num;
            auto nxt = pall.top();
            seen[nxt.second] = 1;
            pall.pop();
            pq.push(nxt);
            total += nxt.first;
        }
        while (seen[pq.top().second] == -1)
            pq.pop();
    }
};



class MKAverage {
public:
    MinHeap mnh;
    MaxHeap mxh;
    int idx = 0;
    v<pi> items;
    int m, k;
    ll total = 0;
    MKAverage(int mm, int kk) {
        m = mm, k = kk;
        mnh.init(k, m);
        mxh.init(k, m);
    }

    void addElement(int num) {
        items.push_back({num, idx});
        if (idx >= m) {
            auto x = items[idx-m];
            mnh.remove(x.first, x.second);
            mxh.remove(x.first, x.second);
            total -= x.first;
        }
        total += num;
        mnh.add(num, idx);
        mxh.add(num, idx);
        idx++;
    }

    int calculateMKAverage() {
        if (idx < m) return -1;
        return total - mnh.total - mxh.total;
    }
};
