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
    public ListNode ModifyNode (ListNode Root, int Pos) {
        ListNode Head = Root;
        while (Pos > 2) {
            Root = Root.next; 
            Pos--;
        }
        ListNode Second = Root.next, Prev = Second, Answer = Second;
        Root.next = null;
        while (Second != null) {
            Prev = Second; 
            Second = Second.next;
        }
        Prev.next = Head;
        return Answer;
    }
    public ListNode rotateRight(ListNode head, int k) {
        int size = 0;
        ListNode Root = head;
        while (Root != null) {
            Root = Root.next; 
            size++;
        }
        if (k != 0 && size > 1){
            k %= size;
            if (k > 0) return ModifyNode (head, size - k + 1);
        }
        return head; 
    }
}