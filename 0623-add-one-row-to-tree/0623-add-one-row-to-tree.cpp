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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If depth is 1, create a new root with original tree as its left child
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        std::queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 1;
        
        // Traverse the tree level by level
        while (!q.empty()) {
            int size = q.size();
            // If we have reached the target depth, add new nodes
            if (currentDepth == depth - 1) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = q.front();
                    q.pop();
                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* rightNode = new TreeNode(val);
                    leftNode->left = node->left;
                    rightNode->right = node->right;
                    node->left = leftNode;
                    node->right = rightNode;
                }
                break;
            }
            // Otherwise, continue traversing
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            currentDepth++;
        }
        
        return root;
    }
};