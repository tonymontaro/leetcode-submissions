// https://leetcode.com/problems/max-stack

class MaxStack {
public:
    /** initialize your data structure here. */
    multiset<pair<int, int>, greater<>> pq;
    stack<pair<int, int>> st;
    set<int> deleted;
    int id = 0;
    MaxStack() {

    }

    void push(int x) {
        pq.insert({x, id});
        st.push({x, id++});
    }

    int pop() {
        auto num = st.top();
        pq.erase(pq.find(num));
        st.pop();
        balance();
        return num.first;
    }

    int top() {
        return st.top().first;
    }

    int peekMax() {
        return pq.begin()->first;
    }
    void balance() {
        while (!st.empty() && deleted.find(st.top().second) != deleted.end()) {
            st.pop();
        }
    }
    int popMax() {
        auto num = *pq.begin();
        deleted.insert(num.second);
        pq.erase(pq.begin());
        balance();
        return num.first;
    }
};
