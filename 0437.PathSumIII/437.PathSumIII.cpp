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
    int pathSum(TreeNode* root, int targetSum) {
        std::map<long long, int> prefixRootMap;
        prefixRootMap[0] = 1;
        int totalCount = 0;

        totalCount = parseTree(root, targetSum, prefixRootMap, 0);

        return totalCount;
    }

    int parseTree(TreeNode* root, int targetSum, std::map<long long, int> &prefixMap, long long curSum) {
        int count = 0;
        
        if (root) {

            curSum += root->val;

            count = prefixMap[curSum - targetSum];
            
            prefixMap[curSum]++;

            if (root->left)
                count += parseTree(root->left, targetSum, prefixMap, curSum);

            if (root->right)
                count += parseTree(root->right, targetSum, prefixMap, curSum);

            prefixMap[curSum]--;
        }

        return count;
    }
};
