class Solution {
public:
    ListNode* mergeKLists(vector <ListNode*> &A) {
        ListNode *k = NULL, *Answer = NULL;
        if (A.size() > 0) {
            priority_queue <pair<int, ListNode*>, vector <pair<int, ListNode*>>, greater <pair<int, ListNode*>>> Data;
            for (int i = 0; i < A.size(); i++) {
                if (A[i]) Data.push({A[i] -> val, A[i]});
            }
            if (!Data.empty()) {
                Answer = Data.top().second;
                Data.pop();
                if (Answer -> next) Data.push({Answer -> next -> val, Answer -> next});
                ListNode* Root = Answer;
                while (!Data.empty()) {
                    ListNode *temp = Data.top().second;
                    Data.pop();
                    Root -> next = temp;
                    Root = temp;
                    if (temp -> next) Data.push({temp -> next -> val, temp -> next});
                }
            }
        }
        return Answer;
    }
};