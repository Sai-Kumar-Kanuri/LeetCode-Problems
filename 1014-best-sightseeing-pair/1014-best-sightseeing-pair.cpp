class Solution {
public:
    int f(int i,int check,vector<int>&values,vector<vector<int>>&dp)
    {
        if(i==values.size())
        {
            if(check)
            {
                return -1e8;
            }
            
            return 0;
        }
        
        if(dp[i][check]!=-1)
        {
            return dp[i][check];
        }
        
        if(check)
        {
            int x=values[i]-i;
            int y=f(i+1,check,values,dp);
            return dp[i][check]=max(x,y);
        }
        
        int x=values[i]+i+f(i+1,1,values,dp);
        int y=f(i+1,0,values,dp);
        return dp[i][check]=max(x,y);
        
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        
        return f(0,0,values,dp);
        
        
    }
};