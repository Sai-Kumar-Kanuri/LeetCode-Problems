class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it: connections)
        {
            adj[it[0]].push_back({it[1],1});
            adj[it[1]].push_back({it[0],0});
        }

        queue<int>q;
        int count=0;
        q.push(0);
        vector<int>vis(n,0);
        vis[0] = 1;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();

            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int direction=it.second;
                if(!vis[adjNode])
                {
                    vis[adjNode]=1;
                    count+=direction;
                    q.push(adjNode);
                }

            }
        }

        return count;
    }
};