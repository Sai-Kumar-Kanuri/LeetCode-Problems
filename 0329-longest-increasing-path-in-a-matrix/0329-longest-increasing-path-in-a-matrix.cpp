class Solution {
public:

    int f(int i,int j,vector<vector<int>>&matrix,int prev,vector<vector<int>>&dp){

        if(i<0 || j<0 || i==matrix.size() || j==matrix[0].size() || prev>=matrix[i][j]){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        
        int u=f(i-1,j,matrix,matrix[i][j],dp);
        int r=f(i,j+1,matrix,matrix[i][j],dp);
        int d=f(i+1,j,matrix,matrix[i][j],dp);
        int l=f(i,j-1,matrix,matrix[i][j],dp);
        
        return dp[i][j]=max({u,r,d,l})+1;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,f(i,j,matrix,-1,dp));
            }
        }
        
        return ans;
    }
};