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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int depth = 0;
        ListNode* cur = head;
        ListNode* prev = head;
        while (cur != nullptr) {
            cur = cur->next;
            depth++;
        }
        cur = head;
        for (int i = 0; i < depth - n; i++) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        if (depth - n == 0) {
            head = head->next;
        }
        return head;
    }
};

