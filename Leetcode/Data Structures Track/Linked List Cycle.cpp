/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *SlowPtr = head, *FastPtr = head -> next;
        while (FastPtr && FastPtr -> next) {
            SlowPtr = SlowPtr -> next;
            FastPtr = FastPtr -> next -> next;
            if (SlowPtr == FastPtr) return true;
        }
        return false;
    }
};