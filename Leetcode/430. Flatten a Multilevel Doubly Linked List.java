class Solution {
    public Node flatten(Node head) {
        return Flattener(head)[0];
    }
    private Node[] Flattener(Node head) {
        Node Start = head, End = null, Saved = null;
        while (head != null) {
            Saved = head;
            Node Next = head.next;
            if (head.child != null) {
                if (End != null) {
                    Node[] Temp = Flattener(head.child);
                    End.next = Temp[0];
                    Temp[0].prev = End;
                    End = (Temp[1] == null) ? End : Temp[1];
                } else {
                    Node[] Temp = Flattener(head.child);
                    End = Temp[1];
                    Temp[0].prev = head;
                    head.next = Temp[0];
                }
                head.child = null;
            }
            if (End != Next && End != null && Next != null) {
                End.next = Next;
                Next.prev = End;
                End = Next;
            }
            head = Next;
        }
        return new Node[]{Start, End == null ? Saved : End};
    }
}