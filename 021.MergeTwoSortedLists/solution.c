/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l3;
    struct ListNode* cur;
    if (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            cur = l1;
            l1 = l1->next;
        }
        else
        {
            cur = l2;
            l2 = l2->next;
        }
    }
    else if (l1 && !l2)
    {
        cur = l1;
        l1 = l1->next;
    }
    else if (l2 && !l1)
    {
        cur = l2;
        l2 = l2->next;
    }
    else
    {
        cur = NULL;
    }
    l3 = cur;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1)
    {
        cur->next = l1;
    }
    else if (l2)
    {
        cur->next = l2;
    }
    return l3;
}


