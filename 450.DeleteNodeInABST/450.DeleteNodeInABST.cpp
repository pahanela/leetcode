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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* repNode = root;
        if (root) {
            if (root->val == key) {
                if (root->left && root->right) {
                    repNode = root->right;
                    TreeNode* curNode = repNode;
                    while (curNode->left)
                        curNode = curNode->left;
                    curNode->left = root->left;
                }
                else if (!(root->left) && root->right)
                    repNode = root->right;
                else if ((root->left) && !(root->right))
                    repNode = root->left;
                else
                    repNode = nullptr;
                delete(root);
            }
            else {
                root->left = deleteNode(root->left, key);
                root->right = deleteNode(root->right, key);
            }
        }
        return repNode;
    }
};

