class Solution {
public:
    int mod = 1e9+7;
    int f(int i,int n,int x,vector<vector<int>>&dp){
        
        if(n==0){
            return 1;
        }
        
        if(n<0 || (n-pow(i,x))<0){
            return 0;
        }
        
        if(dp[i][n]!=-1){
            return dp[i][n];
        }
        
        int take = f(i+1,(n-pow(i,x)),x,dp)%mod;
        int nottake = f(i+1,n,x,dp)%mod;
        
        return dp[i][n]=(take+nottake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,x,dp);
    }
};