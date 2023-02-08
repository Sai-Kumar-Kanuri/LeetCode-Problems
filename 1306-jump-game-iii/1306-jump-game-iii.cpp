class Solution {
public:
    bool f(int i,vector<int>&arr,vector<int>&dp,vector<int>&vis){
        if(i<0 || i>=arr.size() || vis[i]==1){
            return false;
        }
        
        if(arr[i]==0){
            return true;
        }
        
        
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        
        // bool left=false,right=false;
        // if(i+arr[i]<arr.size()){
        //     // int val=arr[i];
        //     // arr[i]=-1;
            vis[i]=1;
           bool right=f(i+arr[i],arr,dp,vis);
        // }
        
//         else if(i-arr[i]>=0){
//             // int val=arr[i];
//             // arr[i]=-1;
//             vis[i]=1;
           bool left=f(i-arr[i],arr,dp,vis);
        // }
        
        return dp[i]=left||right;
        
        
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int>dp(arr.size()+1,-1);
        vector<int>vis(arr.size(),0);
        return f(start,arr,dp,vis);
    }
};