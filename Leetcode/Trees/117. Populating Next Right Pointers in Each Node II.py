class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return
        head = root
        nxt = root.left if root.left else root.right
        while nxt:
            nxt = None
            while head:
                if head.left:
                    if nxt is None:
                        nxt = head.left
                    if head.right:
                        head.left.next = head.right
                    elif head.next:
                        temp = head.next
                        while temp:
                            if temp.left:
                                head.left.next = temp.left
                                break
                            if temp.right:
                                head.left.next = temp.right
                                break
                            temp = temp.next
                if head.right:
                    if nxt is None:
                        nxt = head.right
                    if head.next:
                        temp = head.next
                        while temp:
                            if temp.left:
                                head.right.next = temp.left
                                break
                            if temp.right:
                                head.right.next = temp.right
                                break
                            temp = temp.next
                head = head.next
            head = nxt
        return root
