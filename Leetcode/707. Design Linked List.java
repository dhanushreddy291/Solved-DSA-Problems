class MyLinkedList {
    
    class ListNode {
        int val;
        ListNode next;
        ListNode (int x) {val = x;}
    }

    static int size = 0;
    static ListNode Head, Tail;

    public MyLinkedList() {
        Head = null;
        Tail = null;
        size = 0;
    }
    
    public int get(int index) {
        if (size - 1 < index) return -1;
        else {
            ListNode temp = Head;
            while (index-- > 0) temp = temp.next;
            return temp.val;
        }
    }
    
    public void addAtHead(int val) {
        ListNode temp = new ListNode (val);
        temp.next = Head;
        Head = temp;
        if (size == 0) Tail = Head;
        size++;
    }
    
    public void addAtTail(int val) {
        if (Head == null) addAtHead (val);
        else {
            ListNode temp = new ListNode (val);
            Tail.next = temp;
            Tail = temp;
            size++;
        }
    }
    
    public void addAtIndex(int index, int val) {
        if (size - 1 < index) return;
        else if (index == 0) addAtHead (val);
        else if (index == size - 1) addAtTail (val);
        else {
            index--;
            size++;
            ListNode temp = Head;
            while (index-- > 0) temp = temp.next;
            ListNode temp2 = temp.next;
            ListNode temp3 = new ListNode (val);
            temp3.next = temp2;
            temp.next = temp3;
        }
    }
    
    public void deleteAtIndex(int index) {
        if (size - 1 < index) return;
        else if (index == 0) {
            size--;
            Head = Head.next;
            if (size == 0) Tail = null;
        } else {
            index--;
            size--;
            ListNode temp = Head;
            while (index-- > 0) temp = temp.next;
            if (temp.next == Tail) Tail = temp;
            temp.next = temp.next.next;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */