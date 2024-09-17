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
        TreeNode* rtrn = delNode(root, key, nullptr, false);
        return rtrn;
    }

    /**
     * @brief Deletes the node, frees memory, and links the incoming link
     * @param[in] root - root of the tree to search
     * @param[in] key - key to match
     * @param[in] parent - parent node to link the new one to
     * @param[in] right - flag to indicate the linkage to the parent from the left or right 
    */
    TreeNode* delNode(TreeNode* root, int key, TreeNode* parent, bool right) {
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
                if (parent) {
                    if (right)
                        parent->right = repNode;
                    else
                        parent->left = repNode;
                }
                delete(root);
            }
            else {
                delNode(root->left, key, root, false);
                delNode(root->right, key, root, true);
            }
        }
        return repNode;
    }
};

