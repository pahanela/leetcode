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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsvElements;
        int depth = 0;
        int nextElement = diveBFS(root, depth);
        while (nextElement != BAD_ELEMENT) {
            rsvElements.push_back(nextElement);
            nextElement = diveBFS(root, ++depth);
        }
        return rsvElements;
    }

    const int BAD_ELEMENT = 0xff;

    int diveBFS(TreeNode* root, int depth) {
        int rtrn = BAD_ELEMENT;
        if (root) {
            if (depth == 0) {  // if we reached the desired depth
                if (rtrn == BAD_ELEMENT)
                    rtrn = root->val;
            }
            else {
                --depth;
                rtrn = diveBFS(root->right, depth);
                if (rtrn == BAD_ELEMENT)  // if no right elements found look for the left ones
                    rtrn = diveBFS(root->left, depth);
            }
        }
        return rtrn; 
    }
};

