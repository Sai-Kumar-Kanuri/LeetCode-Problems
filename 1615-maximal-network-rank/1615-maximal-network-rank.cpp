class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>adj(n);
        vector<int>indegree(n,0);
        
        for(auto road:roads){
            adj[road[0]].insert(road[1]);
            adj[road[1]].insert(road[0]);
            indegree[road[0]]++;
            indegree[road[1]]++;
        }
        
        int maxRank=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int currRank = indegree[i]+indegree[j];
                if(adj[i].find(j)!=adj[i].end()){
                    currRank--;
                }
                maxRank=max(currRank,maxRank);
            }
        }
        
        return maxRank;
    }
};