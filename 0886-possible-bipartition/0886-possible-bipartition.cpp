class Solution {
public:
    
    bool bfs(int src, vector<int>adj[],vector<int>&color)
    {
        queue<int>q;
        q.push(src);
        color[src]=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto adjNode: adj[node])
            {
                if(color[adjNode]==-1)
                {
                    color[adjNode]=!color[node];
                    q.push(adjNode);
                }
                if(color[adjNode]==color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>color(n+1,-1);
        vector<int>adj[n+1];
        
        for(auto it:dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,adj,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};