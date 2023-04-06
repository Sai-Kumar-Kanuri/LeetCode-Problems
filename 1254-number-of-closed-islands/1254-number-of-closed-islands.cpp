class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis)
    {
        int m=grid.size();
        int n=grid[0].size();
        if(row<0 || row>=m || col<0 || col>=n)
        {
            return 0;
        }
        
        if(grid[row][col]==1 || vis[row][col])
        {
            return true;
        }
        
        vis[row][col]=1;
        
        int isClosed=1;
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row+drow[i];
            int ncol = col+dcol[i];
            
            if(!dfs(nrow,ncol,grid,vis))
            {
                isClosed=0;
            }
        }
        
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 && !vis[i][j] && dfs(i,j,grid,vis))
                {
                    count++;
                }
            }
        }
        return count;
    }
    
    
};