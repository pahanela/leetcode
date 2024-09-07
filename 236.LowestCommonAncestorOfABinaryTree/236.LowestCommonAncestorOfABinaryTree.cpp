/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* rtrnNode = nullptr;
        bool pFlag = false;
        bool qFlag = false;
        traverseTree(root, p, q, pFlag, qFlag, rtrnNode);

        return rtrnNode;
    }

    void traverseTree(TreeNode* root, TreeNode* p, TreeNode* q, bool &pFound, bool &qFound, TreeNode* &lca) {

        if (root) {
            
            if (root->val == p->val)
                pFound = true;

            if (root->val == q->val)
                qFound = true;

            if (!(pFound && qFound)) {
                traverseTree(root->left, p, q, pFound, qFound, lca);
                traverseTree(root->right, p, q, pFound, qFound, lca);
            }

            if (pFound && qFound && !lca)
                lca = root;
        
        }
      
        return;
    }

    bool findElement
    
};


// check if both are found then set the Node
// if none are found keep searching left and right
// if one is found keep searching for another one
//
