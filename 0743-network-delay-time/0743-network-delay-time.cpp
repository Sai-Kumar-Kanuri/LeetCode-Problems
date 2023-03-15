class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];
        vector<int>dist(n+1,1e8);
        dist[k]=0;
        for(int i=0;i<n;i++)
        {
            for(auto it:times)
            {
                int u=it[0];
                int v=it[1];
                int wt=it[2];
                
               adj[u].push_back({v,wt});
            }
        }
        
        dist[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int node=it.second;
            int dis=it.first;
            pq.pop();
            
            // if(dis>dist[node]){
            //     continue;
            // }
            
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int edgW = it.second;
                
                if(edgW+dis<dist[adjNode])
                {
                    dist[adjNode]=edgW+dis;
                    pq.push({dis+edgW,adjNode});
                }
            }
            
        }
        
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            ans=max(dist[i],ans);
        }
        
        if(ans==1e8)
        {
            ans=-1;
        }
        
        return ans; 
       
    }
};