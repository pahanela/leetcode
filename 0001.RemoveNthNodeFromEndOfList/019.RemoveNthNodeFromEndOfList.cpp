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
        ListNode* cur = head;
        ListNode* prev = head;
        // count only leading pointer first to delay the previous one
        int i = 0;
        for (i = 0; i <= n && cur != nullptr; i++)
            cur = cur->next;
        if (i == n)
            head = head->next;
        else {      
            // count both pointers
            for (int j = 0; cur != nullptr; j++) {
                prev = prev->next;
                cur = cur->next;
            }
            prev->next = prev->next->next;
        }
        return head;
    }
};

