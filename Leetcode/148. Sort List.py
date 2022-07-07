# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head:
            currNode, tailNode = head, None
            while currNode is not None:
                tailNode = currNode
                currNode = currNode.next
            return self.mergeSort(head, tailNode)
        return head

    def mergeSort(self, head, tail):
        if head == tail: return head
        currNode, length = head, 0
        while currNode is not None:
            length += 1
            currNode = currNode.next
        # To get to the middle node the middle node index is (1 + length) / 2 - 1
        length = ((1 + length) // 2) - 1
        currNode = head
        while length > 0:
            length -= 1
            currNode = currNode.next
        rightNode = currNode.next
        currNode.next = None
        return self.merge(self.mergeSort(head, currNode), self.mergeSort(rightNode, tail))

    def merge(self, L, R):
        if L and R:
            head = None
            if L.val < R.val:
                head = L
                L = L.next
            else:
                head = R
                R = R.next
            head.next = self.merge(L, R)
            return head
        elif L:
            return L
        else:
            return R
