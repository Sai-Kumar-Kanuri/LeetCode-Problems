class Solution {
public:
    bool f(int idx,int target,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(target==0)
        {
            return true;
        }
        
        if(idx==0){
            return nums[0]==target;
        }
        
        if(dp[idx][target]!=-1)
        {
            return dp[idx][target];
        }
        
        bool notTake=f(idx-1,target,nums,dp);
        bool take=false;
        
        if(target>=nums[idx])
        {
            take=f(idx-1,target-nums[idx],nums,dp);
        }
        
        
        return dp[idx][target]=take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;
        
        for(auto num:nums){
            totSum+=num;
        }
        
        if(totSum%2!=0)
        {
            return false;
        }
        
        int target=totSum/2;

        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return f(n-1,target,nums,dp);
        
        
    }
};