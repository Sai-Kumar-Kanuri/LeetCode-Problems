class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];

        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int>dist(n,1e9);

        priority_queue<pair<int,pair<int,int>>,
                vector<pair<int,pair<int,int>>>,
               greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,src}});

        dist[src]=0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int stops = it.first;

            if(stops>k){
                continue;
            }

            int cost = it.second.first;
            int node = it.second.second;

            for(auto itr : adj[node]){
                int adjNode = itr.first;
                int nCost = itr.second;

                if(cost+nCost<dist[adjNode]){
                    dist[adjNode]=cost+nCost;
                    pq.push({stops+1,{cost+nCost,adjNode}});
                }
            }
        }

        if(dist[dst]==1e9){
            return -1;
        }

        return dist[dst];
    }
};