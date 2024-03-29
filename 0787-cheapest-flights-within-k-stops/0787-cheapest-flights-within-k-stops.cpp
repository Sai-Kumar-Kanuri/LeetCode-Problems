class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        vector<pair<int,int>>adj[n];//{to,cost}
        
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dist(n,1e9);
        
        
        queue<pair<int,pair<int,int>>>q;//{stops,{node,dist}};
        
        dist[src]=0;
        q.push({0,{src,0}});
        
        
        while(!q.empty()){
            
            auto it = q.front();
            
            int node = it.second.first;
            int dis = it.second.second;
            
            int stops = it.first;
            q.pop();
            
            if(stops>k){
                continue;
            }
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int cost = it.second;
                
                if(dis+cost<dist[adjNode] && stops<=k){
                    dist[adjNode]=dis+cost;
                    q.push({stops+1,{adjNode,dis+cost}});
                }
            }
        }
        
        if(dist[dst]==1e9){
            return -1;
        }
        
        return dist[dst] ;
        
    }
};