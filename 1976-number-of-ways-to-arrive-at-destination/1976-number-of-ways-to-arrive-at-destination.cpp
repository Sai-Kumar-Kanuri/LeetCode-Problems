class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long,long>>adj[n];
        
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>>>pq;
        
        vector<long>dist(n,1e18),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        
        int mod = (int)(1e9+7);
        
        while(!pq.empty())
        {
            auto it = pq.top();
            long long node=it.second;
            long long dis=it.first;
            pq.pop();
            
            for(auto it: adj[node])
            {
                int adjNode=it.first;
                int edgW=it.second;
                
                if(dis+edgW < dist[adjNode])
                {
                    dist[adjNode]=dis+edgW;
                    pq.push({dis+edgW,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dis + edgW == dist[adjNode])
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};