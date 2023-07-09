class Solution {
public:
    int f(bool alice,int i,int M,vector<int>& piles,vector<vector<vector<int>>>&dp){
        
        int n=piles.size();
        if(i>=piles.size()){
            return 0;
        }
        
        if(dp[alice][i][M]!=-1){
            return dp[alice][i][M];
        }
        
        int ans = alice ? 0 : INT_MAX;
        int sum=0;
        
        for(int X=1;X<=2*M && X+i<=n ;X++){
            sum+=piles[X+i-1];
            
            if(alice){
                ans=max(ans,sum+f(!alice,i+X,max(M,X),piles,dp));
            }
            else{
                ans=min(ans,f(!alice,i+X,max(M,X),piles,dp));
            }
        }
        
        return dp[alice][i][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>> (n+1, vector<int> (n+1,-1)));
        return f(true,0,1,piles,dp);
    }
};