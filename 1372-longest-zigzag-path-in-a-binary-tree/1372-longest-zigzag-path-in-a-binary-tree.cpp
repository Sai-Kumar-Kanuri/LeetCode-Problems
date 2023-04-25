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
    int max_ans;
    void f(TreeNode* root,int dir,int ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        max_ans=max(ans,max_ans);
        
        if(dir==0){
            f(root->left,1,ans+1);
            f(root->right,0,1);   
        }
        else{
            f(root->right,0,ans+1);
            f(root->left,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        f(root,0,0);
        f(root,1,0);
        return max_ans;
    }
};