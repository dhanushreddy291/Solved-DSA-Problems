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
        ListNode oddStart = head, evenStart = (head == null) ? head : head.next;
        ListNode odd = oddStart, even = evenStart, lastOdd = head;
        while (odd != null && even != null) {
            lastOdd = odd;
            odd.next = even.next;
            even.next = (even.next == null) ? null : even.next.next;
            odd = odd.next;
            even = even.next;
        }
        if (odd != null) {
            odd.next = evenStart;
        } else if (lastOdd != null) {
            lastOdd.next = evenStart;
        }
        return oddStart;
    }
}