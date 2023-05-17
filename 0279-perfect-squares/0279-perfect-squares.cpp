class Solution {
public:
    int f(vector<int>&arr,int i,int n,int sum,vector<vector<int>>&dp)
    {
        if(sum==0)
        {
            return 0;
        }
        
        if(sum<0 || i>=n)
        {
            return 1e8;
        }
        
        if(dp[i][sum]!=-1)
        {
         return dp[i][sum];   
        }
        
        
        int mini=INT_MAX;
        
        if(arr[i]<=sum)
        {
            mini=min(mini,1+f(arr,i,n,sum-arr[i],dp));
        }
        
        mini=min(mini,f(arr,i+1,n,sum,dp));
        
        return dp[i][sum]=mini;
    }
    int numSquares(int n) {
        
        vector<int>arr;
        
        for(int i=1;i*i<=n;i++)
        {
            arr.push_back(i*i);
        }
        vector<vector<int>>dp(200,vector<int>(n+1,-1));
        return f(arr,0,arr.size(),n,dp);
            
    }
};