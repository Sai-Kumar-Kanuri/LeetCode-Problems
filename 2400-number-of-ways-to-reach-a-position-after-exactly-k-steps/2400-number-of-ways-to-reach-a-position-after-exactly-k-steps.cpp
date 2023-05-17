class Solution {
public:
    int mod = 1e9+7;
    
    int dp[3100][1001];
    
    int f(int s,int e,int k)
    {
        
        if(s==e && k==0)
        {
            return 1;
        }
        
        if(k==0){
            return 0;
        }
        
        if(dp[s+1000][k]!=-1)
        {
            return dp[s+1000][k];
        }
        
        int fwd=f(s+1,e,k-1)%mod;
        int bwd=f(s-1,e,k-1)%mod;
        
        return dp[s+1000][k]=(fwd+bwd)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return f(startPos,endPos,k);
    }
};