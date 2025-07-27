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
    ListNode* oddEvenList(ListNode* head) {
        
        if (!head)
            return head;
        
        ListNode* headEven = head->next;
        ListNode* curOdd = head;
        ListNode* curEven = headEven;

        while (curOdd->next && curEven->next) {
            curOdd->next = curEven->next;
            curOdd = curOdd->next;
            curEven->next = curOdd->next;
            curEven = curEven->next;
        }

        curOdd->next = headEven;

        return head;
    }
};
