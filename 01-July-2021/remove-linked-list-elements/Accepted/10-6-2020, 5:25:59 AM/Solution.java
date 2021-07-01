// https://leetcode.com/problems/remove-linked-list-elements

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
    public ListNode removeElements(ListNode head, int val) {
        ListNode prev = null;
        ListNode node = head;
        while (node != null) {
            if (node.val == val) {
                ListNode next = node.next;
                if (prev != null)
                    prev.next = next;
                else
                    head = next;
                node.next = null;
                node = next;
            } else {
                prev = node;
                node = node.next;
            }
        }
        return head;
    }
}