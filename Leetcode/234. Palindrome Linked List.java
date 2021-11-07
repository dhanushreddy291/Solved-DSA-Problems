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
    public boolean isPalindrome(ListNode head) {
        ListNode slow = head, fast = head.next, head2, head1, slowPrev = null;
        while (fast != null && fast.next != null) {
            slowPrev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        head2 = slow.next;
        if (fast == null) head1 = slowPrev;
        else head1 = slow;
        if (head1 != null) head1.next = null;
        Reverse(head);
        return areTheLinkedListsSame(head1, head2);
    }
    private boolean areTheLinkedListsSame(ListNode head1, ListNode head2) {
        if (head1 == null && head2 == null) return true;
        else if (head1 == null || head2 == null) return false;
        return head1.val == head2.val && areTheLinkedListsSame(head1.next, head2.next);
    }
    private void Reverse(ListNode head) {
        if (head == null) return;
        ListNode Current = head, Prev = null, Next;
        while (Current != null) {
            Next = Current.next;
            Current.next = Prev;
            Prev = Current;
            Current = Next;
        }
    }
}