class Solution {
public:
    bool f(int i,int j,string s1, string s2, string s3,vector<vector<int>>&dp){
        if(i==s1.size() && j==s2.length()){
            return true;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(i<s1.size() && s1[i]==s3[i+j] && f(i+1,j,s1,s2,s3,dp)){
            return true;
        }
        
        if(j<s2.size() && s2[j]==s3[i+j] && f(i,j+1,s1,s2,s3,dp)){
            return true;
        }
        
        return dp[i][j]=false;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())return false;
        
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return f(0,0,s1,s2,s3,dp);
    }
};