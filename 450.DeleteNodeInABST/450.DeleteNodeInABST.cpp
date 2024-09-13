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
        TreeNode* rtrn = root;
        if (root) {
            if (root->val == key) {
                if (root->left == nullptr && root->right == nullptr)
                    root = nullptr;
                else if (root->left == nullptr)
                    root = root->right;
                else if (root->right == nullptr)
                    root = root->left;
                else {
                    if (root->left->left == nullptr) {
                        root->left->left = root->right;
                        root = root->left;
                    }
                    else if (root->left->right == nullptr) {
                        root->left->right = root->right;
                        root = root->left;
                    }
                    else if (root->right->left == nullptr) {
                        root->right->left = root->left;
                        root = root->right;
                    }
                    else if (root->right->right == nullptr) {
                        root->right->right = root->left;
                        root = root->right;
                    }
                }
                rtrn = root;
            }
            else if (root->left && root->left->val == key) {
                if (root->left->left == nullptr)
                    root->left = root->left->right;
                else if (root->left->left == nullptr)
                    root->left = root->left->left;
                else {
                    TreeNode* temp = root->left->right;
                    root->left = root->left->left;
                    root->left->right = temp;
                }
            }
            else if (root->right && root->right->val == key) {
                if (root->right->left == nullptr)
                    root->right = root->right->right;
                else if (root->right->right == nullptr)
                    root->right = root->right->left;
                else {
                    TreeNode* temp = root->left->right;
                    root->left = root->left->left;
                    root->left->right = temp;
                }
            }
            else {
                deleteNode(root->left, key);
                deleteNode(root->right, key);
            }
        }
        return rtrn;
    }
};

