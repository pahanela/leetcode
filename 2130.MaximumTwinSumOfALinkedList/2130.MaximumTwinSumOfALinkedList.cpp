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
    int pairSum(ListNode* head) {

        // find the size of the list
        ListNode* curNode = head;
        int size = 0;
        while (curNode) {
            size++;
            curNode = curNode->next;
        };

        // point to the middle
        curNode = head;
        for (int i = 0; i < size / 2; i++)
            curNode = curNode->next;

        // reverse the second half of the list
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        while (curNode) {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        ListNode* head2 = prevNode;

        // find the max sum
        int max = 0;
        for (int i = 0; i < size / 2; i++) {
            cout << head->val << " " << head2->val << endl;
            if (head->val + head2->val > max)
                max = head->val + head2->val;
            head = head->next;
            head2 = head2->next;
        }

        return max;
    }
};
