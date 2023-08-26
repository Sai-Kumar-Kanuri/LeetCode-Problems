class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n+1,1);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<=i;prev++){
                if(pairs[prev][1]<pairs[i][0]){
                  dp[i]=max(dp[i],1+dp[prev]);  
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};