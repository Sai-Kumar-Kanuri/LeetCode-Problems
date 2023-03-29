class Solution {
public:
    int f(int t,int idx,vector<int>& satisfaction,vector<vector<int>>&dp)
    {
        if(idx==satisfaction.size())
        {
            return 0;
        }
        
        if(dp[idx][t]!=-1)
        {
            return dp[idx][t];
        }
        
        int take=satisfaction[idx]*t+f(t+1,idx+1,satisfaction,dp);
        int nottake=f(t,idx+1,satisfaction,dp);
        
        return dp[idx][t]=max(take ,nottake);
        
        
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>>dp(satisfaction.size()+1,vector<int>(satisfaction.size()+1,-1));
        return f(1,0,satisfaction,dp);
    }
};