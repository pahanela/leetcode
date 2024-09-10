/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = nullptr;
        findElements(root, p, q, false, lca);
        return lca;
    }

    // Function to traverse the tree from root in search of both elements, p and q
    // The flagsFromAbove variable passes search results from top to bottom, to indicate when to stop
    uint8_t findElements(TreeNode* root, TreeNode* p, TreeNode* q, uint8_t flagsFromAbove, TreeNode* &lca) {
        unsigned int flags = 0b00;
        if (root) {
            if (root->val == p->val)
                flags |= 0b10;
            if (root->val == q->val)
                flags |= 0b01;
            if ((flags | flagsFromAbove) != 0x11)
                flags |= \
                    findElements(root->left, p, q, flags | flagsFromAbove, lca) | \
                    findElements(root->right, p, q, flags | flagsFromAbove, lca);
            if (flags == 0b11 && lca == nullptr)
                lca = root;
        }
        return flags;
    }
};

