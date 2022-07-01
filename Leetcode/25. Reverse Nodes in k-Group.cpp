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
    void Reverse(ListNode* root) {
        if (root) {
            ListNode* curr = root, *prev = NULL, *next;
            while (curr) {
                next = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = next;
            }
        }
        return;
    }
    ListNode* helper(ListNode* head, int k) {
        if (head) {
            int size = k - 1;
            ListNode* root = head, *prev = head;
            while (head && size > 0) {
                size--;
                prev = head;
                head = head -> next;
            }
            if (head) {
                ListNode* nextNode = helper(head -> next, k);
                head -> next = NULL;
                Reverse(root);
                root -> next = nextNode;
                return head;
            }
            return root;
        }
        return NULL;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return helper(head, k);
    }
};