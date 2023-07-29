class Solution {
public:
    
    double f(int A,int B,vector<vector<double>>&dp){
        
        if(A<=0 && B>0){
            return 1;
        }
        
        if(A<=0 && B<=0){
            return 0.5;
        }
        
        if(B<=0 && A>0){
            return 0;
        }
        
        if(dp[A][B]!=-1){
            return dp[A][B];
        }
        
        
        double ans= (f(A-100,B,dp)+f(A-75,B-25,dp)+f(A-50,B-50,dp)+f(A-25,B-75,dp))/4;
        
        return dp[A][B]=ans;
    }
    double soupServings(int n) {
        
        if(n>=5000){
            return 1;
        }
        
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1));
        
        
        
        return f(n,n,dp);
    }
};