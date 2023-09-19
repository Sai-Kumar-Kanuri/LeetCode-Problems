class Solution {
public:
    bool isPalindrome(string &s,int low,int high){
        while(low<=high){
            if(s[low]!=s[high]){
                return false;
            }
            
            low++;
            high--;
        }
        
        return true;
    }
    int f(int start,string &s,vector<int>&dp){
        if(start==s.length()){
            return -1;
        }
        
        if(dp[start]!=-1){
            return dp[start];
        }
        
        int mini = 1e9;
        for(int end=start;end<s.length();end++){
            if(isPalindrome(s,start,end)){
                int cut = 1+f(end+1,s,dp);
                mini=min(cut,mini);
            }
        }
        
        
        return dp[start]=mini;
    }
    int minCut(string s) {
        int n = s.length();
        
        vector<int>dp(n,-1);
        
        return f(0,s,dp);
    }
};