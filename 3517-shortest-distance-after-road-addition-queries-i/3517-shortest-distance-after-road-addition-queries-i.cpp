class Solution {
public:
    void f(int n,vector<int>adj[],vector<int>&ans){

        queue<int>q;
        q.push(0);
        vector<int>vis(n,0);
        vis[0]=1;
        vector<int>dist(n,1e9);
        dist[0]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjNode : adj[node]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                    dist[adjNode] = 1+dist[node];
                    vis[adjNode]=1;
                }
            }
        }

        ans.push_back(dist[n-1]);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>adj[n];

        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }

        vector<int>ans;

        for(auto it : queries){
            adj[it[0]].push_back(it[1]);
            f(n,adj,ans);
        }

        return ans;
    }
};