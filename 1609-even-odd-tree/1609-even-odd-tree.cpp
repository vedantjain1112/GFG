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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool isEvenLevel = true;
        
        while (!q.empty()) {
            int levelSize = q.size();
            int prevVal = isEvenLevel ? INT_MIN : INT_MAX; 
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                if ((isEvenLevel && (node->val % 2 == 0 || node->val <= prevVal)) ||
                    (!isEvenLevel && (node->val % 2 != 0 || node->val >= prevVal))) {
                    return false;
                }
                
                prevVal = node->val;
            
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            isEvenLevel = !isEvenLevel;
        }
        
        return true;
    }
};