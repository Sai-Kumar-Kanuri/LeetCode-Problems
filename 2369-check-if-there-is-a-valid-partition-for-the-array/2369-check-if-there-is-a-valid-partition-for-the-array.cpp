class Solution {
public:
    
    bool f(int i,vector<int>&nums,vector<int>&dp){
        
        if(i==nums.size()){
            return true;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        bool ans1=false,ans2=false,ans3=false;
        
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            ans1 = f(i+2,nums,dp);
        }
        
        if(i+2<nums.size() && nums[i]==nums[i+1] && nums[i]==nums[i+2]){
            ans2 = f(i+3,nums,dp);
        }
        
        if(i+2<nums.size() && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1){
            ans3 = f(i+3,nums,dp);
        }
        
        if( ans1 || ( ans2 || ans3 )){
            return dp[i]=true;
        }
        
        return dp[i]=false;
        
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(0,nums,dp);
    }
};