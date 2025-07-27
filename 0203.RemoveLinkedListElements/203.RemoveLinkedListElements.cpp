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
        ListNode* newHead = head;
        ListNode* cur = newHead;
        if (cur == NULL)
            return head;
        while (cur != NULL && cur->val == val) {
            newHead = cur->next;
            cur = newHead;
        }
        while (cur != NULL && cur->next != NULL) {
            cout << cur->val << endl;
            if (cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        };
        return newHead;
    };
};

