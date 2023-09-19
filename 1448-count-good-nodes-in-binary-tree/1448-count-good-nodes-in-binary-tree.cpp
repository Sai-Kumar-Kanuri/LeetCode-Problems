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
    int f(TreeNode* node,int maxi){
        if(node==NULL){
            return 0;
        }
        
        int res;
        
        if(node->val>=maxi){
            res=1;
        }else{
            res=0;
        }
        
        maxi=max(maxi,node->val);
        
        int left = f(node->left,maxi);
        int right = f(node->right,maxi);
        
        
        res=res+left+right;
        
        return res;
    }
    int goodNodes(TreeNode* root) {
        return f(root,root->val);
    }
};