/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int maxSum = 0;
        ListNode* slowPtr = head, *fastPtr = head -> next;
        stack <int> Stack;
        Stack.push(slowPtr -> val);
        while (fastPtr -> next) {
            slowPtr = slowPtr -> next;
            Stack.push(slowPtr -> val);
            fastPtr = fastPtr -> next -> next;
        }
        slowPtr = slowPtr -> next;
        while (!Stack.empty()) {
            maxSum = max(maxSum, Stack.top() + slowPtr -> val);
            slowPtr = slowPtr -> next;
            Stack.pop();
        }
        return maxSum;
    }
};