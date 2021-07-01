// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> pq;
    int mx;
    KthLargest(int k, vector<int>& nums) {
        mx = k;
        for (auto x: nums) {
            add(x);
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > mx) pq.pop();
        return pq.top();
    }
};