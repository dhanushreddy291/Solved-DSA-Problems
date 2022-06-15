# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slowPtr, fastPtr, Stack, maxSum = head, head.next, [head.val], 0
        while fastPtr.next:
            slowPtr = slowPtr.next
            Stack.append(slowPtr.val)
            fastPtr = fastPtr.next.next
        slowPtr = slowPtr.next
        while len(Stack):
            maxSum = max(maxSum, slowPtr.val + Stack[-1])
            Stack.pop()
            slowPtr = slowPtr.next
        return maxSum