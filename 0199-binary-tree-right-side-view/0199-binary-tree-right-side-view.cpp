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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        
        if(root==NULL){
            return res;
        }
        
        
        
        queue<pair<TreeNode*,int>>q;
        map<int,int>mp;
        
        q.push({root,0});
        
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            
            TreeNode* node = it.first;
            int level=it.second;
            
            mp[level]=node->val;
            
            if(node->left){
                q.push({node->left,level+1});
            }
            
            if(node->right){
                q.push({node->right,level+1});
            }
            
        }
        
        for(auto it: mp){
            res.push_back(it.second);
        }
        
        return res;
    }
};