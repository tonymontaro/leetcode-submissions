// https://leetcode.com/problems/max-stack

class MaxStack {
public:
    /** initialize your data structure here. */
    multiset<int, greater<>> pq;
    stack<int> st;
    map<int, int> count;
    MaxStack() {

    }

    void push(int x) {
        pq.insert(x);
        st.push(x);
    }

    int pop() {
        int num = st.top();
        pq.erase(pq.find(num));
        st.pop();
        balance();
        return num;
    }

    int top() {
        return st.top();
    }

    int peekMax() {
        return *pq.begin();
    }
    void balance() {
        while (!st.empty() && count[st.top()] > 0) {
            count[st.top()]--;
            st.pop();
        }
    }
    int popMax() {
        int num = *pq.begin();
        count[num]++;
        pq.erase(pq.begin());
        balance();
        return num;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */