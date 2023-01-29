class Solution {
public:
    bool solve(int i,vector<int>&x,vector<int>&dp)
    {
        int n=x.size();
        if(i>=n-1)
            return true;
        if(x[i]==0)
            return false;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=1;j<=x[i];j++)
            if(i+j<n)
                if(solve(i+j,x,dp))
                    return dp[i]=true;

        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(0,nums,dp);
    }
};