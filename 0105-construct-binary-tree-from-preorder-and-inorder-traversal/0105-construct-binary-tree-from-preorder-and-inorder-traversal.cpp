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
    int find(vector<int>& inorder, int num)
    {
        for( int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==num)
            return i;
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index, int inorderStart, int inorderEnd, int n){
        if(index>=n || inorderStart>inorderEnd) return NULL;

        TreeNode* root=new TreeNode(preorder[index]);
        int position=find(inorder,preorder[index]);
        index++;
        root->left=solve(preorder,inorder, index, inorderStart,position-1,n);
        root->right=solve(preorder,inorder, index, position+1,inorderEnd,n);
        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderStart=0;
        int inorderStart=0;
        int n = inorder.size();
        int inorderEnd=n-1;
        TreeNode* ans =  solve(preorder,inorder, preorderStart, inorderStart, inorderEnd, n);
        return ans;
    }
};