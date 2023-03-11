class Solution {
public:
    int f(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>&dp,int n){
        
        if(ind==n){
            return 0;
        }
        
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        
        int nottake=0+f(ind+1,prev_ind,nums,dp,n);
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
             take=1+f(ind+1,ind,nums,dp,n);
        }
        
        return dp[ind][prev_ind+1]=max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,-1,nums,dp,n);
    }
};