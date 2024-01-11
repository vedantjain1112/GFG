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
    int maxAncestorDiff(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return helper(root, root->val, root->val);
    }

private:
    int helper(TreeNode* node, int min_val, int max_val) {
        if (!node) {
            return max_val - min_val;
        }

        // Update min_val and max_val based on the current node's value
        min_val = std::min(min_val, node->val);
        max_val = std::max(max_val, node->val);

        // Recursively calculate maxAncestorDiff for left and right subtrees
        int left_diff = helper(node->left, min_val, max_val);
        int right_diff = helper(node->right, min_val, max_val);

        // Return the maximum difference obtained from left and right subtrees
        return std::max(left_diff, right_diff);
    }
};
