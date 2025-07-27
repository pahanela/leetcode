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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;

        traverseTreeForLeaves(root1, leaves1);
        traverseTreeForLeaves(root2, leaves2);

        if (leaves1 == leaves2)
            return true;
        else
            return false;
    }

    void traverseTreeForLeaves(TreeNode* root, vector<int> &leaves) {
        if (root) {
            if (root->left)
                traverseTreeForLeaves(root->left, leaves);
            if (root->right)
                traverseTreeForLeaves(root->right, leaves);
            if (!root->left && !root->right)
                leaves.push_back(root->val);
        }
    }
};
