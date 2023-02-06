class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp(n,1),hash(n);
//         int maxi=1,lastIndex=0;
//         for(int i=0;i<n;i++){
//             hash[i]=i;
//             for(int prev=0;prev<i;prev++){
//                 if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
//                     dp[i]=1+dp[prev];
//                     hash[i]=prev;
//                 }
//             }
//             if(dp[i]>maxi){
//             maxi=dp[i];
//             lastIndex=i;
//             }
//         }
//         vector<int> temp;
//     temp.push_back(nums[lastIndex]);
    
//     while(hash[lastIndex] != lastIndex){ 
//         lastIndex = hash[lastIndex];
//         temp.push_back(nums[lastIndex]);    
//     }
    
//     reverse(temp.begin(),temp.end());

    
//     return temp;
        
         int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = 1, last = 0;
        vector<int>dp(n,1), hash(n);

        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                 
                 if(nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]){
                     dp[i] = 1 + dp[j];
                     hash[i] = j;
                 }
            }

            if(dp[i] > maxi){
                maxi  = dp[i];
                last = i;
            }
        }
        
        vector<int>ans;
        ans.push_back(nums[last]);
       
        while(hash[last] != last){
            last = hash[last];
            ans.push_back(nums[last]);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};