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
    
    TreeNode* sortedArrToBST(vector<int>&nums,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        
        int mid=start+(end-start)/2;
        
        TreeNode*head = new TreeNode(nums[mid]);
        head->left=sortedArrToBST(nums,start,mid-1);
        head->right=sortedArrToBST(nums,mid+1,end);
        return head;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        TreeNode*root=new TreeNode();
        root=sortedArrToBST(nums,start,end);
        return root;
    }
};