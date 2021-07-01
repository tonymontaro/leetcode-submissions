// https://leetcode.com/problems/flatten-nested-list-iterator

class NestedIterator {
public:
    stack<NestedInteger> vec;
    NestedIterator(vector<NestedInteger> &nestedList) {
        add(nestedList);
    }
    void add(vector<NestedInteger> &nestedList) {
        if (nestedList.empty()) return;
        for (int i = nestedList.size() - 1; i >= 0; i--) vec.push(nestedList[i]);
    }

    int next() {
        if (vec.empty()) return -1;
        int ans = vec.top().getInteger();
        vec.pop();
        return ans;
    }

    bool hasNext() {
        while (!vec.empty() && !vec.top().isInteger()) {
            auto ls = vec.top().getList();
            vec.pop();
            add(ls);
        }
        return !vec.empty();
    }
};