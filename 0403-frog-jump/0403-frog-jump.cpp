class Solution {
public:
    bool solve(int i, int next, vector<int>&stones, unordered_map<int,int>&mp,vector<vector<int>>&dp){
        if(i==stones.size()-1)
            return true;
        
        if(dp[i][next]!=-1)
        {
            return dp[i][next];
        }
        
        int nex = stones[i]+next;
            
        if(!mp.count(nex) || mp[nex]==i)
            return false;
        
        return dp[i][next]=solve(mp[nex],next-1,stones,mp,dp) || solve(mp[nex],next,stones,mp,dp) || solve(mp[nex],next+1,stones,mp,dp);
        
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[stones[i]]=i;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,1,stones,mp,dp);
    }
    
};