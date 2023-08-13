class Solution {
public:
    
    bool f(int i,vector<int>&nums,vector<int>&dp){
        
        if(i==nums.size()){
            return true;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        // bool ans1=false,ans2=false,ans3=false;
        bool res=false;
        
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            res = f(i+2,nums,dp);
        }
        
        if(i+2<nums.size() && nums[i]==nums[i+1] && nums[i]==nums[i+2]){
            res = res || f(i+3,nums,dp);
        }
        
        if(i+2<nums.size() && nums[i]==nums[i+1]-1 && nums[i+1]==nums[i+2]-1){
            res = res || f(i+3,nums,dp);
        }
        
        return dp[i]=res;
        
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(0,nums,dp);
    }
};