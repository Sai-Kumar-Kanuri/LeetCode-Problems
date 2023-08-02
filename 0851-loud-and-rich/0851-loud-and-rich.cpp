class Solution {
public:
    int dfs(int node, vector<vector<int>>&adj, vector<int>& quiet, vector<int>&ans){
        if(ans[node]==-1){
            ans[node]=node;
            for(auto adjNode : adj[node]){
                int candidate = dfs(adjNode,adj,quiet,ans);
                if(quiet[candidate]<quiet[ans[node]]){
                    ans[node]=candidate;
                }
            }
        }
        return ans[node];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        
        
        for(auto it: richer){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>ans(n,-1);
        
        for(int i=0;i<n;i++){
            dfs(i,adj,quiet,ans);
        }
        
        return ans;   
    }
};