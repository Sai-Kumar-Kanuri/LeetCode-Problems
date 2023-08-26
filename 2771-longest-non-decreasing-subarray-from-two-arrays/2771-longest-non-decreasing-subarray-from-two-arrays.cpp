class Solution {
public:
    int f(int i,int flag,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>&dp){
        
        if(i==nums1.size()){
            return 0;
        }
        
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        
        if(flag==0){
            int pick1 = f(i+1,1,nums1,nums2,dp)+1;
            int pick2 = f(i+1,2,nums1,nums2,dp)+1;
            int pick0 = f(i+1,0,nums1,nums2,dp);
            
            return dp[i][flag]=max({pick0,pick1,pick2});
        }
        
        if(flag==1){
            int pick1=0,pick2=0;
            if(nums1[i-1]<=nums1[i]){
                pick1 = f(i+1,1,nums1,nums2,dp)+1;
            }
            if(nums1[i-1]<=nums2[i]){
                pick2=f(i+1,2,nums1,nums2,dp)+1;
            }
            return dp[i][flag]=max(pick1,pick2);
        }
        if(flag==2){
            int pick1=0,pick2=0;
            if(nums2[i-1]<=nums1[i]){
                pick1 = f(i+1,1,nums1,nums2,dp)+1;
            }
            if(nums2[i-1]<=nums2[i]){
                pick2=f(i+1,2,nums1,nums2,dp)+1;
            }
            return dp[i][flag]=max(pick1,pick2);
        }
        
        return dp[i][flag]=0;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return f(0,0,nums1,nums2,dp);
        
    }
};