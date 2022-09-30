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
    
    TreeNode* prev = NULL;
    vector<pair<TreeNode*, TreeNode*>> v;
    
    //inorder trvaersal
    void solve(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        
        solve(root->left);
        if(prev != NULL) {
            if(prev->val > root->val) {
                v.push_back(make_pair(root, prev));
            }
        }
        prev = root;
        solve(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        solve(root);
        if(v.size() == 1) {
            swap(v[0].first->val, v[0].second->val);
        } else {
            swap(v[0].second->val, v[1].first->val);    
        }
    }
};