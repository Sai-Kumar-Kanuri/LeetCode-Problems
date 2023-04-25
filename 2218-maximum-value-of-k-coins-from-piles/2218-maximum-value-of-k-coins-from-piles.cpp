class Solution {
public:
    int f(int i,int coins,vector<vector<int>>& piles,vector<vector<int>>&dp)
    {
        if(i>=piles.size())
        {
            return 0;
        }
        
        if(coins==0)
        {
            return 0;
        }
        
        if(dp[i][coins]!=-1)
        {
            return dp[i][coins];
        }
        
        int result=f(i+1,coins,piles,dp);
        
        int cur=0;
        for(int j=0;j<min(coins,int(piles[i].size()));j++)
        {
            cur+=piles[i][j];
            result=max(result,cur+f(i+1,coins-j-1,piles,dp));
        }
        
        return dp[i][coins]=result;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return f(0,k,piles,dp);
        
    }
};