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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>result;
        
        if(root==NULL)
        {
            return result;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* node;  
            while(!q.empty())
            {
                int n=q.size();
                vector<int>temp;
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
                        temp.push_back(node->val);
                    }
                result.push_back(temp);
            }
        reverse(result.begin(),result.end());
        return result;
    }
};