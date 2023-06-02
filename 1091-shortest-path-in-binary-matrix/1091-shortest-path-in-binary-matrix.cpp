class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        // int m=grid[0].size();
        if(grid[0][0]==1){
            return -1;
        }
        
        if(n==1){
            return 1;
        }
        
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int nrow=row+i;
                    int ncol= col+j;
                    
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol]){
                        dist[nrow][ncol]=dis+1;
                        if(nrow==n-1 && ncol==n-1){
                            return dis+1;
                        }
                        q.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return -1;
        
        
    }
};