class Solution {
public:
    int f(int ind,vector<vector<int>>&dp,vector<int>&arr,int target){

    if(ind==0){
      if (target == 0 && arr[0] == 0) {
        return 2;
      }
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }

    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = f(ind-1,dp,arr,target);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = f(ind-1,dp,arr,target-arr[ind]);
        
    return dp[ind][target]= (notTaken + taken);
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    // cout<<n<<"n"<<"d"<<d<<endl;
    int totsum=0;
    for(auto x:arr){
        totsum+=x;
    }
    
    if((totsum-d)<0){
        return 0;
    }

    if((totsum-d)%2){
        return 0;
    }

    int target=(totsum-d)/2;
    // cout<<"target"<<target<<endl;
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return f(n-1,dp,arr,target);


}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums.size(),target,nums);
    }
};