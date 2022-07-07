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
    private ListNode findMidNode(ListNode head) {
        ListNode midNode = head;
        while (head != null && head.next != null && head.next.next != null) {
            head = head.next.next;
            midNode = midNode.next;
        }
        return midNode;
    }
    private ListNode mergeLists(ListNode A, ListNode B) {
        if (A != null && B != null) {
            if (A.val > B.val) return mergeLists(B, A);
            ListNode head = A;
            head.next = mergeLists(A.next, B);
            return head;
        }
        if (A != null) return A;
        return B;
    }
    private ListNode mergeSort(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode mid = findMidNode(head);
        if (mid != null) {
            ListNode rightNode = mid.next;
            mid.next = null;
            return mergeLists(mergeSort(head), mergeSort(rightNode));
        }
        return mid;
    }
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
}