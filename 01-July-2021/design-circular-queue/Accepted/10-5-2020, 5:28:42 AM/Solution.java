// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
    int capacity;
    int n;
    Node head;
    Node tail;

    /**
     * Initialize your data structure here. Set the size of the queue to be k.
     */
    public MyCircularQueue(int k) {
        capacity = k;
        n = 0;
    }

    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     */
    public boolean enQueue(int value) {
        if (n == capacity) return false;
        Node node = new Node(value);
        if (n == 0) {
            head = node;
        } else {
            tail.next = node;
        }
        tail = node;
        n++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    public boolean deQueue() {
        if (n == 0) return false;
        Node node = head.next;
        head.next = null;
        head = node;
        n--;
        if (n == 0)
            tail = null;
        return true;
    }

    /** Get the front item from the queue. */
    public int Front() {
        if (n==0) return -1;
        return head.val;
    }

    /** Get the last item from the queue. */
    public int Rear() {
        if (n == 0) return -1;
        return tail.val;
    }

    /** Checks whether the circular queue is empty or not. */
    public boolean isEmpty() {
        return n == 0;
    }

    /** Checks whether the circular queue is full or not. */
    public boolean isFull() {
        return n == capacity;
    }

    class Node {
        int val;
        public Node next;

        Node(int val) {
            this.val = val;
        }
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */