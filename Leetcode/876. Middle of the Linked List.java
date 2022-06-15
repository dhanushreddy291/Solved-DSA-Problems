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
    public ListNode middleNode(ListNode head) {
        if (head.next == null) return head;
        ListNode slowPtr = head, FastPtr = head.next;
        while (FastPtr != null) {
            if (FastPtr.next == null) return slowPtr.next;
            FastPtr = FastPtr.next.next;
            slowPtr = slowPtr.next;
        }
        return slowPtr;
    }
}