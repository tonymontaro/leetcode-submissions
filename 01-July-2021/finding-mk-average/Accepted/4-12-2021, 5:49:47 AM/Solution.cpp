// https://leetcode.com/problems/finding-mk-average

#define ll long long
#define umap unordered_map
#define uset unordered_set
#define pii pair<int, pair<int, int>>
#define pi pair<int, int>
#define v vector




class MKAverage {
public:
    int m, k, midSize;
    int idx = 0;
    ll total = 0;
    v<int> arr;
    multiset<int> left, mid, right;
    MKAverage(int m, int k) : m(m), k(k), midSize(m - 2 * k) {
        arr = v<int>(m);
    }
    void remove(int num){
        auto found = left.find(num);
        if (found != left.end()) {
            left.erase(found);
        } else {
            found = mid.find(num);
            if (found != mid.end()) {
                total -= num;
                mid.erase(found);
            } else {
                found = right.find(num);
                right.erase(num);
            }
        }
        rebalance();
    }
    void add(int num) {
        left.insert(num);
        if (idx >= m)
            rebalance();
    }
    void rebalance() {
        while (left.size() < k) {
            auto lowestMid = mid.begin();
            left.insert(*lowestMid);
            total -= *lowestMid;
            mid.erase(lowestMid);
        }
        while (left.size() > k) {
            auto highestLeft = --left.end();
            total += *highestLeft;
            mid.insert(*highestLeft);
            left.erase(highestLeft);
        }
        while (mid.size() < midSize) {
            auto lowestRight = right.begin();
            total += *lowestRight;
            mid.insert(*lowestRight);
            right.erase(lowestRight);
        }
        while (mid.size() > midSize) {
            auto highestMid = --mid.end();
            right.insert(*highestMid);
            total -= *highestMid;
            mid.erase(highestMid);
        }
    }

    void addElement(int num) {
        if (idx >= m) {
            remove(arr[idx % m]);
        }
        arr[idx % m] = num;
        idx++;
        add(num);
        
    }

    int calculateMKAverage() {
        if (idx < m) return -1;
        return total / midSize;
    }
};