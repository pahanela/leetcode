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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;

        if (!head->next)
            return NULL;

        // identify the middle node
        ListNode* cur = head;
        while (cur->next) {
            cur = cur->next;
            count++;
        }
        int middleIndex = (count - 1) / 2;

        // find the middle node and remove it
        count = 0;
        cur = head;
        while (count != middleIndex) {
            cur = cur->next;
            count++;
        }

        cur->next = cur->next->next;

        return head;
    }
};

