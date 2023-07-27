class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==0)
            return {};
        if(n==1)
            return {0};
        
        
        vector<int>indegree(n,0);
        
        vector<int>adj[n];
        
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        
        vector<int>res;
        
        while(!q.empty()){
            
            res.clear();
            
            int t = q.size();
            
            while(t--){
                auto it=q.front();
                q.pop();
                res.push_back(it);
                for(auto node : adj[it]){
                    indegree[node]--;
                    if(indegree[node]==1){
                        q.push(node);
                    }
                }
            }
        }
        
        return res;
    }
};