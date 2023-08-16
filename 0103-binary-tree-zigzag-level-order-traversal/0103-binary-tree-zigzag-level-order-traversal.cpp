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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root==NULL) return ans;

        queue<TreeNode*>q;
        q.push(root);
        int count = 0;
        vector<int>temp;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size;i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if (count%2==0) ans.push_back(temp);
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            temp.clear();
            count++;

        }
        return ans;

    }
};