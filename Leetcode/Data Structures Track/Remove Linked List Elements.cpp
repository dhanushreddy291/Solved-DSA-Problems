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
    ListNode* removeElements(ListNode* head, int val) {
        if (head) {
            ListNode* Root = head;
            while (Root && Root -> val == val)
                Root = Root -> next;
            head = Root;
            while (Root) {
                ListNode* temp = Root -> next;
                while (temp && temp -> val == val)
                    temp = temp -> next;
                Root -> next = temp;
                Root = temp;
            }
        }
        return head;
    }
};