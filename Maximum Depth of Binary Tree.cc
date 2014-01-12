/**
 * Given a binary tree, find its maximum depth.
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int max(int leftDepth, int rightDepth) {
        if(leftDepth > rightDepth)
            return leftDepth;
        else
            return rightDepth;
    }
    
    int maxDepth(TreeNode *&root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val = 1;
        else {
            root->val = max(maxDepth(root->left),maxDepth(root->right)) + 1;
        }
        return root->val;
    }
};