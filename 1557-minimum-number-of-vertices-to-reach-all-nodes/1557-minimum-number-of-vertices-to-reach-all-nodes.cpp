class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>in_degree(n,false);
        
        for(auto edge:edges){
            in_degree[edge[1]]=true;
        }
        
        vector<int>res;
        
        for(int i=0;i<n;i++)
        {
            if(!in_degree[i])
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};