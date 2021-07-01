// https://leetcode.com/problems/design-hashset

class MyHashSet {
public:
    /** Initialize your data structure here. */
    int seen[1000001];
    MyHashSet() {
        memset(seen, -1, sizeof(seen));
    }

    void add(int key) {
        seen[key] = 1;
    }

    void remove(int key) {
        seen[key] = -1;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return seen[key] == 1;
    }
};