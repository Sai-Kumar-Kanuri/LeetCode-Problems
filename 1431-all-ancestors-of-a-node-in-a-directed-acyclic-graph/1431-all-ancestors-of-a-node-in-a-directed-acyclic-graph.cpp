class Solution {
public:
    void dfs(int node,int currNode,vector<int>adj[],vector<vector<int>>&ans,vector<int>&vis){
        
        vis[currNode]=1;
        for(auto it:adj[currNode]){
            if(!vis[it]){
                ans[it].push_back(node);
                dfs(node,it,adj,ans,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<int>adj[n];
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<vector<int>>ans(n);
        
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            dfs(i,i,adj,ans,vis);
        }
        return ans;
    }
};