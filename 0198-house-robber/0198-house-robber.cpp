class Solution {
public:
    int f(int idx,vector<int>&nums,vector<int>&dp){
    if(idx==0){
        return nums[0];
    }
    if(idx<0){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int pick=nums[idx]+f(idx-2,nums,dp);
    
    int notpick=f(idx-1,nums,dp);
    
    return dp[idx]=max(pick,notpick);
}
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return f(nums.size()-1,nums,dp);
    }
};