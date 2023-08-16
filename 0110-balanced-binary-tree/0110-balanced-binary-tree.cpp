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
    int balanced(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = balanced(root->left);
        if (lh == -1) return -1; // Imbalance detected in the left subtree

        int rh = balanced(root->right);
        if (rh == -1) return -1; // Imbalance detected in the right subtree

        if (abs(lh - rh) > 1) return -1; // Imbalance detected in current node

        return max(lh, rh) + 1; // Return the height of the current node
    }

    // Main function to check if the binary tree is balanced
    bool isBalanced(TreeNode* root) {
        int height = balanced(root);
        if (height == -1)
            return false; // Imbalance detected in the tree
        else
            return true; // Tree is balanced
    }
};