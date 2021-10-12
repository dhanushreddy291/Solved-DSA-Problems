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
    public ListNode swapPairs(ListNode head) {
        if (head != null) {
            if (head.next != null) {
                ListNode first = head, second = head.next, third = head.next.next;
                second.next = first;
                first.next = swapPairs (third);
                head = second;
            }
        }
        return head;
    }
}