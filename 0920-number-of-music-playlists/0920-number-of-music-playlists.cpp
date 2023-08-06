class Solution {
public:
    int mod = 1e9+7;
    long long f(int old_songs,int cur_goal,int n,int k,vector<vector<long long>>&dp){
        
        if(cur_goal==0 && old_songs==n){
            return 1;
        }
        
        if(cur_goal==0 || old_songs>n){
            return 0;
        }
        
        if(dp[old_songs][cur_goal]!=-1){
            return dp[old_songs][cur_goal];
        }
        
        
        long long count = (f(old_songs+1,cur_goal-1,n,k,dp)*(n-old_songs))%mod;
        // cout<<count<<endl;
        
        if(old_songs>k){
            count += (f(old_songs,cur_goal-1,n,k,dp)*(old_songs-k))%mod;
        }
        
        return dp[old_songs][cur_goal]=(int)(count%mod);
        
        
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>>dp(n+1,vector<long long>(goal+1,-1));
        return f(0,goal,n,k,dp);
    }
};