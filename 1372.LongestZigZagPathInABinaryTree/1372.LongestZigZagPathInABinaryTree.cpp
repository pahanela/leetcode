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
    int longestZigZag(TreeNode* root) {
        int max = 0;

        if (root) {
            int altLeft = countAltNodes(root->left, true);
            int altRight = countAltNodes(root->right, false);
            int maxLeft = longestZigZag(root->left);
            int maxRight = longestZigZag(root->right);

            if (altLeft > maxLeft)
                maxLeft = altLeft;

            if (altRight > maxRight)
                maxRight = altRight;

            if (maxLeft > maxRight)
                max = maxLeft;
            else
                max = maxRight;
        }

        return max;
    }

    int countAltNodes(TreeNode* root, bool dir) {
        int len = 0;
        TreeNode* nextNode = nullptr;

        if (root) {
            len++;
            if (dir)
                nextNode = root->right;
            else
                nextNode = root->left;
            len += countAltNodes(nextNode, !dir);
        }

        return len;
    }
};

