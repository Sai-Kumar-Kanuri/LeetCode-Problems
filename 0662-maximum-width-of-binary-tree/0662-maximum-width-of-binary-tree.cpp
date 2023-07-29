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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int ans=0;
        queue<pair<TreeNode*,long>>q;
        q.push({root,0});
        
        while(!q.empty()){
            int curMin = q.front().second;
            int left,right;
            int n=q.size();
            
            for(int i=0;i<n;i++){
                
                long curr_id = q.front().second-curMin;
                TreeNode* node = q.front().first;
                
                q.pop();
                
                if(i==0){
                    left=curr_id;
                }
                
                if(i==n-1){
                    right=curr_id;
                }
                
                if(node->left){
                    q.push({node->left,curr_id*2+1});
                }
                
                if(node->right){
                    q.push({node->right,2*curr_id+2});
                }
                
                 
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};