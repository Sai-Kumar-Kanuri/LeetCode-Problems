class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.length();
        
        vector<int> indegree(n, 0); 
        vector<int>adj[n];
        
        for(auto &it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        vector<vector<int>>count(n,vector<int>(26));
        
        queue<int>q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        int answer=0,nodeSeen=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            answer=max(answer,++count[node][colors[node]-'a']);
            nodeSeen++;
            
            for(auto adjNode:adj[node])
            {
                for(int i=0;i<26;i++)
                {
                    count[adjNode][i]=max(count[adjNode][i],count[node][i]);
                }
                indegree[adjNode]--;
                if(indegree[adjNode]==0)
                {
                    q.push(adjNode);
                }
            }
            
            
        }
         return nodeSeen < n ? -1 : answer;
    }
};