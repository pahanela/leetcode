/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    bool rtrn = false;
    struct ListNode *p_cur1 = head;
    struct ListNode *p_cur2 = head;
    while(rtrn == false)
    {
        if (p_cur1 != NULL)
        {
            p_cur1 = p_cur1->next;
        }
        else
        {
            break;
        }
        if (p_cur2 != NULL && p_cur2->next != NULL)
        {
            p_cur2 = p_cur2->next->next;
        }
        else
        {
            break;
        }
        if (p_cur1 == p_cur2)
        {
            rtrn = true;
        }
    }
    return rtrn;
}
