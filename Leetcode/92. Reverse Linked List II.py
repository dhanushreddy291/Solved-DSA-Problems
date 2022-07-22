class Solution:

    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        root, startEnd = head, None
        while right > 1:
            if left == 2:
                startEnd = root
            left -= 1
            right -= 1
            root = root.next
        endStart = root.next
        root.next = None
        if startEnd is None:
            (X, Y) = self.Reverse(head)
            Y.next = endStart
            return X
        else:
            (X, Y) = self.Reverse(startEnd.next)
            startEnd.next = X
            Y.next = endStart
            return head

    def Reverse(self, root):
        Prev, Curr, Next = None, root, root        
        while Curr is not None:
            Next = Curr.next
            Curr.next = Prev
            Prev = Curr
            Curr = Next
        return (Prev, root)
