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
    ListNode* RemoveNode (ListNode* Root, int Pos) {
        if (Pos == 1) return Root -> next;
        ListNode* Answer = Root;
        while (Pos > 2) {Root = Root -> next; Pos--;}
        Root -> next = Root -> next -> next;
        return Answer;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode *Root = head;
        while (Root) {Root = Root -> next; size++;}
        return RemoveNode (head, size - n + 1);
    }
};