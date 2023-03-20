class Solution {
public:
    int mod=1e9+7;
    int f(int i,int j,int m,int n,int maxMove,vector<vector<vector<int>>>&dp)
    {
        if((i==m || i<0 || j==n || j<0) && maxMove>=0) 
        {
            return 1;
        }
        
        if(maxMove<=0)
        {
            return 0;
        }
        
        if(dp[i][j][maxMove]!=-1)
        {
            return dp[i][j][maxMove];
        }
        
        int count=0;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int k=0;k<4;k++)
        {
            count=(count+f(i+drow[k],j+dcol[k],m,n,maxMove-1,dp))%mod;
        }
        
        return dp[i][j][maxMove]=(count)%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return f(startRow,startColumn,m,n,maxMove,dp);
    }
};