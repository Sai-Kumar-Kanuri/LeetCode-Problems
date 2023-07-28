class Solution {
public:
    int f(int l,int r,bool player,vector<int>& nums, vector<vector<int>>&dp){
        if(l>r){
            return -1;
        }
        
        if(l==r){
            return nums[l];
        }
        
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        
        
        if(player){
            dp[l][r]=max(nums[l]+f(l+1,r,!player,nums,dp),nums[r]+f(l,r-1,!player,nums,dp));
        }else{
            dp[l][r]=min(-nums[l]+f(l+1,r,!player,nums,dp),-nums[r]+f(l,r-1,!player,nums,dp));
        }
        
        return dp[l][r];
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        
        return f(0,n-1,true,nums,dp)>=0;
        
    }
};