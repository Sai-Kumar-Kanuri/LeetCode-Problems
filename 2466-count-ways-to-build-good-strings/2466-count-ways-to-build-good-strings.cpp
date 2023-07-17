class Solution {
public:
    int mod=1e9+7;
    int f(int low, int high, int zero, int one,int length,vector<int>&dp){
        if(length>high){
            return 0;
        }
        
        if(dp[length]!=-1){
            return dp[length];
        }
        
        int res=0;
        
        if(length>=low && length<=high) {
            res +=1 ;
        }

        
        res=(res+f(low,high,zero,one,length+zero,dp)+f(low,high,zero,one,length+one,dp))%mod;
        
        return dp[length]=res%mod;
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return f(low,high,zero,one,0,dp);
    }
};