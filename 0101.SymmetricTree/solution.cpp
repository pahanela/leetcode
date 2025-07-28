/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        bool rtrn;

        if (root)
            rtrn = isMirrorTree(root->left, root->right);
        else
            rtrn = true;

        return rtrn;
    }

private:
    bool isMirrorTree(TreeNode* p, TreeNode* q) {
        bool rtrn;
        
        if (p && q && p->val == q->val)
            rtrn = isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
        else if (!p && !q)
            rtrn = true;
        else
            rtrn = false;

        return rtrn;
    }

};

