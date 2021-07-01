// https://leetcode.com/problems/odd-even-linked-list

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode odd = head;
        ListNode even = head.next;
        ListNode firstEven = even;
        ListNode node = even.next;
        int parity = 1;
        while (node != null) {
            if (parity == 1) {
                odd.next = node;
                odd = node;
            } else {
                even.next = node;
                even = node;
            }
            node = node.next;
            parity = (parity + 1) % 2;
        }
        odd.next = firstEven;
        even.next = null;
        return head;
    }
}