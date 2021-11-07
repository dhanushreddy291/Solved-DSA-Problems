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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return sumTwoLists(l1, l2, 0);
    }
    private ListNode sumTwoLists(ListNode l1, ListNode l2, int Carry) {
        if (l1 == null && l2 == null) {
            if (Carry == 0) return null;
            else return new ListNode(Carry);
        } else {
            int A = (l1 == null) ? 0 : l1.val, B = (l2 == null) ? 0 : l2.val;
            int Sum = A + B + Carry, newCarry = 0;
            ListNode head = (l1 == null) ? l2 : l1;
            head.val = Sum;
            if (Sum > 9) {
                head.val = Sum % 10;
                newCarry = Sum / 10;
            }
            head.next = sumTwoLists(l1 == null ? null : l1.next, l2 == null ? null : l2.next, newCarry);
            return head;
        }
    }
}