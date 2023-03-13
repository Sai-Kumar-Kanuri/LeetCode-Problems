class Solution {
public:
    int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(i==s1.length() && j==s2.length())
        {
            return 0;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(i==s1.length() && j!=s2.length())
        {
            return dp[i][j]=f(i,j+1,s1,s2,dp)+s2[j];
        }
        
        if(j==s2.length() && i!=s1.length())
        {
            return dp[i][j]=f(i+1,j,s1,s2,dp)+s1[i];
        }
        
        
        if(s1[i]==s2[j])
        {
            return dp[i][j]=f(i+1,j+1,s1,s2,dp);
        }
        
        else{
            int x=f(i+1,j,s1,s2,dp)+s1[i];
            int y=f(i,j+1,s1,s2,dp)+s2[j];
            return dp[i][j]=min(x,y);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
       int m = s1.size(), n = s2.size();
    
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(0,0,s1,s2,dp);
    }
};