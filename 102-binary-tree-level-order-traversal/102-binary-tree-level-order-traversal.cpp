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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>map;
        if(root==NULL)
        {
            return map;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* node;
        
        while(!q.empty())
        {
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                node=q.front();
                if(node->left)
                {
                    q.push(node->left);
                }
                if(node->right)
                {
                    q.push(node->right);
                }
                q.pop();
                cout<<node->val<<" ";
                temp.push_back(node->val);
                cout<<i<<endl;
            }
            map.push_back(temp);
        }
        return map;
        
    }
};