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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* rtrn = nullptr;
        if (root) {
            if (root->val == val)
                rtrn = root;
            else {
                rtrn = searchBST(root->left, val);
                if (!rtrn)
                    rtrn = searchBST(root->right, val);
            }
        }
        return rtrn;
    }
};

