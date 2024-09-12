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
    int maxLevelSum(TreeNode* root) {
        int minLevel = 0;
        int maxSum = -100000;
        vector<int> sums;
        diveBFS(root, sums, 1);
        for (int i = 1; i < sums.size(); i++) {
            if (sums[i] > maxSum) {
                maxSum = sums[i];
                minLevel = i;
            }
        }
        return minLevel;
    }

    void diveBFS(TreeNode* root, vector<int> &sums, int level) {
        if (root) {
            if (sums.size() < level + 1)
                sums.resize(level + 1);
            sums[level] += root->val;
            level++;
            diveBFS(root->left, sums, level);
            diveBFS(root->right, sums, level);
        }
        return;
    }
};

