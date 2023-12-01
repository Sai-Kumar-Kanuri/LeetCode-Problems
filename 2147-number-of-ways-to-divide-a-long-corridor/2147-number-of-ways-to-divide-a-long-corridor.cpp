class Solution {
public:
    const int MOD = 1e9+7;

    int f(int index,int seats,string& corridor,vector<vector<int>>&dp){

        if(index==corridor.length()){
            return seats==2?1:0;
        }

        if(dp[index][seats]!=-1){
            return dp[index][seats];
        }

        int result = 0;

        if(seats==2){
            if(corridor[index]=='S'){
                result = f(index+1,1,corridor,dp)%MOD;
            }else{
                result = (f(index+1,0,corridor,dp)+f(index+1,2,corridor,dp))%MOD;
            }
        }else{
            if(corridor[index]=='S'){
                result = f(index+1,seats+1,corridor,dp)%MOD;
            }else{
                result = f(index+1,seats,corridor,dp)%MOD;
            }
        }

        return dp[index][seats]=result;
    }
    int numberOfWays(string corridor) {
        int n = corridor.length();

        vector<vector<int>>dp(n+1,vector<int>(3,-1));

        return f(0,0,corridor,dp);
    }
};