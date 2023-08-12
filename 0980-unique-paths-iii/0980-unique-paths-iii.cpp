class Solution {
public:
          
        int dr[4]={-1,0,+1,0};
        int dc[4]={0,+1,0,-1};
    int f(int row,int col,int steps,vector<vector<int>>&grid,int totStepsCnt)
    {
        
        if(grid[row][col]==2) 
        {
            return steps==totStepsCnt;
        }
        
        int orig=grid[row][col];
        grid[row][col]=-1;
  
        int paths=0;
        for(int i=0;i<4;i++)
        {
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                
                if(nrow<grid.size() && nrow>=0 && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol]!=-1)
                {
                    paths+=f(nrow,ncol,steps+1,grid,totStepsCnt);    
                }
        }
        
        grid[row][col]=orig;
            
        return paths;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int i,j;//start point
        int stepCnt=0;
        for(int row=0;row<grid.size();row++)
        {
            for(int col=0;col<grid[0].size();col++)
            {
                if(grid[row][col]==1)
                {
                    i=row;
                    j=col;
                }
                if(grid[row][col]!=-1) stepCnt++;
            }
        }
        
        
        return f(i,j,1,grid,stepCnt);
        
        
    }
};