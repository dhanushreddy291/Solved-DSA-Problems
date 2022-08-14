class Solution {
    private:
        unordered_map <int, int> Map;
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* root = head;
        while (root != NULL) {
            Map[root -> val]++;
            root = root -> next;
        }
        root = head;
        ListNode* dummy = new ListNode(0), curr = dummy;
        while (root != NULL) {
            if (Map[root -> val] == 1) {
                curr -> next = root;
                curr = root;
            }
            root = root -> next;
        }
        curr -> next = NULL;
        return dummy -> next;
    }
};