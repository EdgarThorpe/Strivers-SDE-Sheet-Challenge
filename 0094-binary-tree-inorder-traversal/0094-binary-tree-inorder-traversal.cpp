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
    
        // vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        // if(root!=NULL){
        //     // if(root==NULL) return;
        //     inorderTraversal(root->left);
        //     ans.push_back(root->val);
        //     inorderTraversal(root->right);
        // }
        // return ans;   

        vector<int>inorder;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                inorder.push_back(curr->val); 
                curr=curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right = curr;
                    curr=curr->left;
                }
                else{
                    //when prev->right = NULL
                    //1. cut the thread
                    //2. print curr
                    //3, make curr go right
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }     
        return inorder;
        
    }
};