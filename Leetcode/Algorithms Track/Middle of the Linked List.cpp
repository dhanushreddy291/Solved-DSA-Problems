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
    ListNode* middleNode(ListNode* head) {
        if (head) {
            ListNode *Slow = head, *Fast = Slow -> next;
            while (Fast && Fast -> next) {
                Slow = Slow -> next;
                Fast = Fast -> next -> next;
            }
            return Fast ? Slow -> next : Slow;
        }
        return head;
    }
};