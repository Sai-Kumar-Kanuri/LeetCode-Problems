class Solution {
public:
    int f(int index,int flag,vector<int>& stoneValue,vector<vector<int>>&dp){
        
        if(index>=stoneValue.size()){
            return 0;
        }
        
        if(dp[index][flag]!=-1){return dp[index][flag];}
        
        
        int ans = flag ? -1e8 : 1e8;
        // int ans=flag==1?INT_MIN:INT_MAX;
        int sum=0;
        
        for(int i=1;i<=3 && index+i-1<stoneValue.size();i++){
            sum+=stoneValue[index+i-1];
            
            if(flag){
                ans=max(ans,sum+f(index+i,!flag,stoneValue,dp));
            }
                else{
                ans=min(ans,f(index+i,!flag,stoneValue,dp)-sum);
            }
        }
        
        
        
        return dp[index][flag]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int ans=f(0,1,stoneValue,dp);
        
        if(ans>0){
            return "Alice";
        }else if(ans<0){
            return "Bob";
        }
        return "Tie";
    }
};