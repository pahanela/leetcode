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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode;
        ListNode* cur = l3;
        int i = 0;
        while (l1 or l2) {
            if (l1) {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                cur->val += l2->val;
                l2 = l2->next;
            }
            if (l1 or l2 or cur->val / 10)
                cur->next = new ListNode;
            if (cur->val / 10)
                cur->next->val = cur->val / 10;
            cur->val %= 10;
            cur = cur->next;

            if (!l1 and !l2) {
                if (cur) {
                    if (cur->val / 10) {
                        cur->next = new ListNode;
                        cur->next->val = cur->val / 10;
                    }
                    cur->val %= 10;
                }
                break;
            }
        }
        return l3;
    }
};

