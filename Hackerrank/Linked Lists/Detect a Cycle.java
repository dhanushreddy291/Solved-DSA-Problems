/*
Detect a cycle in a linked list. Note that the head pointer may be 'null' if the list is empty.

A Node is defined as: 
    class Node {
        int data;
        Node next;
    }
*/

boolean hasCycle(Node head) {
    if (head != null) {
            Node SlowPtr = head, FastPtr = head.next;
            while (FastPtr != null && FastPtr.next != null) {
                SlowPtr = SlowPtr.next;
                FastPtr = FastPtr.next.next;
                if (SlowPtr == FastPtr) return true;
            }
        }
        return false;
}