class Solution {
public:
    int getParity(int n){
        return n%2==0;
    }
    
    long long f(int i,int x,int parity,vector<int>& nums,vector<vector<long long>>&dp){
        
        if(i==nums.size()){
            return 0;
        }
        
        if(dp[parity][i]!=-1){
            return dp[parity][i];
        }
        
        long long pick=0;
        long long notPick =0;
        int currParity = getParity(nums[i]);
        
        if(currParity==parity){
            pick = nums[i]+f(i+1,x,currParity,nums,dp);
        }else{
            pick = nums[i]-x+f(i+1,x,currParity,nums,dp);
        }
        
        notPick = f(i+1,x,parity,nums,dp);
        
        return dp[parity][i]=max(pick,notPick);
        
        
    }
    long long maxScore(vector<int>& nums, int x) {
        
        long long n = nums.size();
        vector<vector<long long>>dp(3,vector<long long>(n+1,-1));
        return f(0,x,getParity(nums[0]),nums,dp);
    }
};