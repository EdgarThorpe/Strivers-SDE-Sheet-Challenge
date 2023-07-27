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

    int find(vector<int> &postorder,int num){
        for(int i = 0; i < postorder.size(); i++){
            if(postorder[i] == num){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int &preordStrt, int postordStrt, int postordEnd, int n){
        if(preordStrt >= n || postordStrt > postordEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preordStrt]);
        preordStrt++;
        if(postordStrt == postordEnd) return root;
        int pos = find(postorder,preorder[preordStrt]);
        root->left = solve(preorder,postorder,preordStrt,postordStrt, pos,n);
        root->right = solve(preorder,postorder,preordStrt,pos+1, postordEnd-1,n);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int preordStrt = 0;
        int postordStrt = 0;
        int postordEnd = n-1;
        return solve(preorder, postorder, preordStrt, postordStrt, postordEnd,n);


    }
};