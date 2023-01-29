class Solution {
public:
    int lcs(string str1,string str2) {
        int n=str1.size();
        int m=str2.size();
        
        if(n==0){
            return m;
        }
        
        if(m==0){
            return n;
        }

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=i;
        }

        for(int j=0;j<m;j++){
            dp[0][j]=j;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }

                else{
                    // dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
            return dp[n][m];
        }
    int minDistance(string w1, string w2) {
        
        int n = w1.length();
        int m = w2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int j=0;j<=m;j++) dp[0][j] = j;
        for(int i=0;i<=n;i++) dp[i][0] = i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(w1[i-1] == w2[j-1]){
                    dp[i][j] = dp[i-1][j-1];    
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
                
            }
        }
        return dp[n][m];
        
    }
};