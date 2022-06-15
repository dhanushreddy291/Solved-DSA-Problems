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
private:
    int getSize(ListNode* head) {
        if (head) return 1 + getSize(head -> next);
        else return 0;
    }
public:
    int getDecimalValue(ListNode* head) {
        int N = 0, size = getSize(head);
        while (head) {
            N |= (head -> val << --size);
            head = head -> next;
        }
        return N;
    }
};