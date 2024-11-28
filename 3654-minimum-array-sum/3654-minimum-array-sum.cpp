class Solution {
public:
    int f(int idx,int op1,int op2,int k,vector<int>&nums,vector<vector<vector<int>>>&dp){

        if(idx == nums.size()){
            return 0;
        }

        int ans = INT_MAX;

        if(dp[idx][op1][op2]!=-1){
            return dp[idx][op1][op2];
        }

        if(op1>0){
            int case1 = ceil((double)(nums[idx])/(double)(2)) + f(idx+1,op1-1,op2,k,nums,dp);
            ans = min(ans,case1);
        }

        if(op2>0 && nums[idx]>=k){
            int case2 = (nums[idx]-k) + f(idx+1,op1,op2-1,k,nums,dp);
            ans = min(ans,case2);
        }


        if(op1>0 && op2>0){
            int case3 = ceil((double)(nums[idx])/(double)(2));

            if(case3>=k){
                case3 =  (case3-k) + f(idx+1,op1-1,op2-1,k,nums,dp);
                ans = min(ans,case3);
            }

            if(nums[idx]>=k){
                int case4 = (nums[idx]-k);
                case4 = ceil((double)(case4)/(double)(2)) + f(idx+1,op1-1,op2-1,k,nums,dp);
                ans=min(ans,case4);
            }
        }

        int case5 = nums[idx] + f(idx+1,op1,op2,k,nums,dp);

        ans = min(ans,case5);

        return dp[idx][op1][op2] = ans;
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {

        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));

        
        return f(0,op1,op2,k,nums,dp);
    }
};