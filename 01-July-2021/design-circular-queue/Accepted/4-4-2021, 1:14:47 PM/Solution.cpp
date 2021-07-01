// https://leetcode.com/problems/design-circular-queue

#define v vector


class MyCircularQueue {
public:
    v<int> arr;
    int write = 0, read = 0, n = 0;
    int cnt = 0;
    MyCircularQueue(int k) {
        arr.reserve(k);
        n = k;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        cnt++;
        arr[write] = value;
        write = (write + 1) % n;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        cnt--;
        read = (read + 1) % n;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[read];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[(read + cnt - 1) % n];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == n;
    }
};