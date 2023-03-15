class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<pair<int,int>>adj[n];
        for(auto it: flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        queue<pair<int,pair<int,int>>>q; //{stops,{node,dist}}
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0,{src,0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            int node=it.second.first;
            int dis = it.second.second;
            
            int stops = it.first;
            
            q.pop();
            
            if(stops>K)
            {
                continue;
            }
            
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int edgW=it.second;
                
                if(dis+edgW < dist[adjNode] && stops<=K)
                {
                    dist[adjNode]=dis+edgW;
                    q.push({stops+1,{adjNode,dis+edgW}});
                }
            }
        }
        
        if(dist[dst]==1e9)
        {
            return -1;
        }
        
        return dist[dst];
        
    }
};