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
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        
        if(root==NULL)
        {
            return ans;
        }
        
        q.push(root);
        int f=0;
        
        while(!q.empty())
        {
            int n=q.size();
            vector<int>sub;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                sub.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                
                if(temp->right) q.push(temp->right);

            }
            if(f==1)
            {
                reverse(sub.begin(),sub.end());
                f=0;
            }
            else{
                f=1;
            }
            ans.push_back(sub);
        }
        return ans;
    }
};