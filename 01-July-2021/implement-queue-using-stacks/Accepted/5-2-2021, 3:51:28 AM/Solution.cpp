// https://leetcode.com/problems/implement-queue-using-stacks

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> sin;
    stack<int> sout;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        sin.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        balance();
        int num = sout.top();
        sout.pop();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        balance();
        return sout.top();
    }
    void balance() {
        if (sout.empty()) {
            while (!sin.empty()) {
                sout.push(sin.top());
                sin.pop();
            }
        }
    }
    /** Returns whether the queue is empty. */
    bool empty() {
        return sin.empty() && sout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */