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
    void getSum(TreeNode* root,int &ans,int sum)
    {
        if(root==NULL){
            return ;
        }
        
        sum=sum*10+root->val;
        cout<<sum<<endl;
        
        if(root->left==NULL && root->right==NULL)
        {
            ans+=sum;
            cout<<"ANS"<<ans<<endl;
        }
        
        getSum(root->left,ans,sum);
        getSum(root->right,ans,sum);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int ans=0;
        getSum(root,ans,0);
        return ans;
    }
};