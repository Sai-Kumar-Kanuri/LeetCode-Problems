class Solution {
public:
    
    int manDist(vector<int>&a,vector<int>&b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                adj[i].push_back({j,manDist(points[i],points[j])});
                adj[j].push_back({i,manDist(points[i],points[j])});
            }
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> vis(n, 0);
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int node = it.second;
            int dist = it.first;
            
            if(vis[node]==1) continue;
            
            sum+=dist;
            vis[node]=1;
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edgWt = it.second;
                
                if(vis[adjNode]==0){
                    pq.push({edgWt,adjNode});
                }
            }
        }
        
        return sum;
    }
};