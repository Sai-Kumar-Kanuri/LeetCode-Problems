class Solution {
public:
    int f(int amount,vector<int>&coins,int ind,vector<vector<int>>&dp){
        if(ind==0){
            return amount%coins[0]==0;
        }
        
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        
        int nottake = f(amount,coins,ind-1,dp);
        
        int take=0;
        
        if(coins[ind]<=amount){
            take=f(amount-coins[ind],coins,ind,dp);
        }
        
        return dp[ind][amount]=take+nottake;
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return f(amount,coins,coins.size()-1,dp);
    }
};