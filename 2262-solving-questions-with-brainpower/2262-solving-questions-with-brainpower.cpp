class Solution {
public:
    long long f(int i,vector<vector<int>>&questions,vector<long long>&dp){

        if(i>=questions.size()){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        long long pick = 0;
        pick = questions[i][0] + f(i+questions[i][1]+1,questions,dp);

        long long notPick = f(i+1,questions,dp);

        return dp[i]=max(pick,notPick);
    }
    long long mostPoints(vector<vector<int>>& questions) {

        vector<long long>dp(questions.size(),-1);
        return f(0,questions,dp);
    }

};