class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        if(i>=nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int count=1e8;
        for(int j=1;j<=nums[i];j++){
            count=min(1+f(i+j,nums,dp),count);
        }
        
        return dp[i]=count;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return f(0,nums,dp);
    }
};