# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        return self.helper(head, k)
        
    def Reverse(self, head: Optional[ListNode]):
        currNode, prevNode, nextNode = head, None, None
        while currNode:
            nextNode = currNode.next
            currNode.next = prevNode
            prevNode = currNode
            currNode = nextNode
        return
    
    def helper(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if head:
            size = k - 1
            root, prev = head, head
            while head and size > 0:
                size -= 1
                prev = head
                head = head.next
            if head:
                nextNode = self.helper(head.next, k)
                head.next = None
                self.Reverse(root)
                root.next = nextNode
                return head
            return root
        return None