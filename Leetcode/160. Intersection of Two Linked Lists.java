/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public int FindSize (ListNode temp) {
        int size = 0;
        while (temp != null) {
            temp = temp.next;
            size++;
        }
        return size;
    }
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode temp1 = headA, temp2 = headB;
        int size1 = FindSize (headA), size2 = FindSize (headB);
        if (size1 * size2 > 0) {
            temp1 = headA;
            temp2 = headB;
            while (size1 > size2) {
                temp1 = temp1.next; 
                size1--;
            }
            while (size1 < size2) {
                temp2 = temp2.next; 
                size2--;
            }
            while (temp1 != null) {
                if (temp1 == temp2) 
                    return temp1;
                temp1 = temp1.next;
                temp2 = temp2.next;
            }
        }
        return null;
    }
}