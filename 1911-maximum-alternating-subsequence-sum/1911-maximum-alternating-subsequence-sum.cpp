class Solution {
public:
    long long f(int idx,int flag,vector<int>&nums,vector<vector<long long>>&dp)
    {
        if(idx>=nums.size())
        {
            return 0;
        }
        if(dp[idx][flag]!=-1)
        {
            return dp[idx][flag];
        }
        
        long long ans=0;
        if(flag)
        {
            ans=max(f(idx+1,0,nums,dp)-nums[idx],f(idx+1,1,nums,dp));
        }
        else{
            ans=max(f(idx+1,1,nums,dp)+nums[idx],f(idx+1,0,nums,dp));
        }
        return dp[idx][flag]=ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        long long n = nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return f(0,0,nums,dp);
        
    }
};