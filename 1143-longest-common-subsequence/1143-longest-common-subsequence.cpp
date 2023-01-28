class Solution {
public:
        int f(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
        if(i>=t1.length() || j>=t2.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int c=0;
        if(t1[i]==t2[j]){
            c=1+f(i+1,j+1,t1,t2,dp);
        }
        else{
            c=max(f(i,j+1,t1,t2,dp),f(i+1,j,t1,t2,dp));
        }
        return dp[i][j]=c;
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length(),vector<int>(text2.length(),-1));
        return f(0,0,text1,text2,dp);
    }
};