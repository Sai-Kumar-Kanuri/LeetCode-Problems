class Solution {
public:
    int f(int i,int prevJump,vector<int>& stones,unordered_map<int,int>&mp,vector<vector<int>>&dp){
        
        if(i==stones.size()-1){
            return 1;
        }
        
        if(dp[i][prevJump]!=-1){
            return dp[i][prevJump];
        }
        
        int ans = false;
        
        for(int nextJump =prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump>0 && mp.find(stones[i]+nextJump)!=mp.end()){
                ans = ans||f(mp[stones[i]+nextJump],nextJump,stones,mp,dp);
            }
        }
        
        return dp[i][prevJump]=ans;
    }
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(0,0,stones,mp,dp);
    }
};