class Solution {
public:
    int f(int i,int k,vector<int>&arr,vector<int>&dp)
    {
        if(i==arr.size())
        {
            return 0;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        int maxi=arr[i];
        int ans=-1e8;
        
        for(int j=i;j<(i+k);j++)
        {
            if(j==arr.size())
            {
              break;
            }
            
            maxi=max(arr[j],maxi);
            ans=max(ans,maxi*(j-i+1)+f(j+1,k,arr,dp));
        }
        
        
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return f(0,k,arr,dp);
    }
};