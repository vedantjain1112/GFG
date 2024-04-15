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
    int sumNumbers(TreeNode* root) {
        return sumRootToLeaf(root, 0);
    }
    
    int sumRootToLeaf(TreeNode* root, int sumSoFar) {
        if (!root) return 0;
        
        sumSoFar = sumSoFar * 10 + root->val;
        
        
        if (!root->left && !root->right) return sumSoFar;
        
        return sumRootToLeaf(root->left, sumSoFar) + sumRootToLeaf(root->right, sumSoFar);
    }
};