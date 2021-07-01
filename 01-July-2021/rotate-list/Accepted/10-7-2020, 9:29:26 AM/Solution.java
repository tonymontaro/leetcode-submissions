// https://leetcode.com/problems/rotate-list

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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return head;
        int ln = 0;
        ListNode last = null;
        ListNode node = head;
        while (node != null){
            ln++;
            last = node;
            node = node.next;
        }
        if (k % ln == 0) return head;
        k = k % ln;
        int diff = ln - k;
        node = head;
        while (diff > 1){
            node = node.next;
            diff--;
        }
        last.next = head;
        head = node.next;
        node.next = null;
        return head;
    }
}