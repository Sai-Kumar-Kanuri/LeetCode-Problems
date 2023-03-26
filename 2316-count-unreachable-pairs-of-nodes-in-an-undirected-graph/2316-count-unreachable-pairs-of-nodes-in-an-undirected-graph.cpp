class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int>&vis,long long &count)
    {
        vis[node]=1;
        count++;
        for(auto adjNode:adj[node])
        {
            if(!vis[adjNode])
            {
                dfs(adjNode,adj,vis,count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        long long m = n ;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int>vis(n,0);
        // vis[0]=1;
        
        long long ans= (long long)((m*(m-1))/2);
        // cout<<"ans "<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            // cout<<vis[i]<<" "<<i<<endl;
            if(!vis[i])
            {
                long long count=0;
                dfs(i,adj,vis,count);
                ans-=(long long)((count*(count-1))/2);
                // cout<<"count "<<count<<endl;
            }
        }
        
        return ans;
        
    }
};