// https://leetcode.com/problems/evaluate-reverse-polish-notation

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto &x: tokens) {
            int a, b;
            if (x == "+") {
                setLastTwo(a, b, st);
                st.push(a + b);
            } else if (x == "-") {
                setLastTwo(a, b, st);
                st.push(a - b);
            } else if (x == "*") {
                setLastTwo(a, b, st);
                st.push(a * b);
            } else if (x == "/") {
                setLastTwo(a, b, st);
                st.push(a / b);
            } else {
                st.push(stoi(x));
            }
        }
        return st.top();
    }
    void setLastTwo(int &a, int &b, stack<int> &st){
        b = st.top();
        st.pop();
        a = st.top();
        st.pop();
    }
};