class Solution {
public:
    int f(int idx,vector<int>&nums,int rem,vector<vector<int>>&dp){

        if(idx==nums.size()){
            if(rem==0){
                return 0;
            }else{
                return -1e8;
            }
        }

        if(dp[idx][rem]!=-1){
            return dp[idx][rem];
        }

        int pick = 0;
        
        pick = nums[idx] + f(idx+1,nums, (rem + nums[idx]%3)%3,dp);;


        int notPick = f(idx+1,nums,rem,dp);

        return dp[idx][rem]=max(pick,notPick);
        

        
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(3,-1));
        return f(0,nums,0,dp);
    }
};