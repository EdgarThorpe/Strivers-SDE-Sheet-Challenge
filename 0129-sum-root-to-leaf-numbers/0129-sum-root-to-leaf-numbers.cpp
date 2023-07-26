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
private:
    int rootToLeaf = 0;

public:
    void preorder(TreeNode* r, int currNumber) {
        if (r != nullptr) {
            currNumber = currNumber * 10 + r->val;
            // if it's a leaf, update root-to-leaf sum
            if (r->left == nullptr && r->right == nullptr) {
                rootToLeaf += currNumber;
            }
            preorder(r->left, currNumber);
            preorder(r->right, currNumber);
        }
    }

    int sumNumbers(TreeNode* root) {
        preorder(root, 0);
        return rootToLeaf;
    }
};
