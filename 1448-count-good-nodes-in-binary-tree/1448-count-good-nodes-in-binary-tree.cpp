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
    int goodNodes(TreeNode* root) {
        
        return dfs(root,INT_MIN);
    }
    
    int dfs(TreeNode* root,int curr_max){
        
        if(!root){
            return 0;
        }
        int val=0;
        if(curr_max<=root->val)
        {
            val++;
        }
        curr_max=max(curr_max,root->val);
        return dfs(root->left,curr_max)+dfs(root->right,curr_max)+val;
            
        
    }
};