/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head;
    struct ListNode *cur;
    int carry = 0;
    if (l1)
        head = l1;
    else
        head = l2;
    while (l1 || l2 || carry){
        if (l1 && l2){
            cur = l1;
            cur->val = l1->val + l2->val + carry;
            if (cur->val > 9){
                cur->val -= 10;
                carry = 1;
            }
            else
                carry = 0;
            l1 = l1->next;
            l2 = l2->next;
        }
        else if (l1){
            cur = l1;
            cur->val = l1->val + carry;
            if (cur->val > 9){
                cur->val -= 10;
                carry = 1;
            }
            else
                carry = 0;
            l1 = l1->next;
        }
        else if (l2){
            cur->next = l2;
            cur = cur->next;
            cur->val = l2->val + carry;
            if (cur->val > 9){
                cur->val -= 10;
                carry = 1;
            }
            else
                carry = 0;
            l2 = l2->next;
        }
        else{
            cur->next = calloc(1, sizeof(struct ListNode*));
            cur = cur->next;
            cur->val = 1;
            carry = 0;
        }
    }
    return head;
}
