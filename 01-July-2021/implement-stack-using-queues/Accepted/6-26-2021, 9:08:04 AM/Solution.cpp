// https://leetcode.com/problems/implement-stack-using-queues

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
        
    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            int last = q.front();
            q.pop();
            q.push(last);
        }
        int ans = q.front();
        q.pop();
        return ans;
    }

    /** Get the top element. */
    int top() {
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};