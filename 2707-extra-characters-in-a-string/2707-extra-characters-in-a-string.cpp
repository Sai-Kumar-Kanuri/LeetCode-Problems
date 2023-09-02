class Solution {
public:
    int f(int i,string s,unordered_set<string>&dictionarySet,vector<int>&dp){
        if(i==s.length()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        // int ans = INT_MAX;
        
        int ans=1+f(i+1,s,dictionarySet,dp);
        
        cout<<i<<" "<<ans<<endl;
        
        for(int j=i;j<s.length();j++){
            auto curr = s.substr(i,j-i+1);
            if(dictionarySet.count(curr)){
                ans=min(ans,f(j+1,s,dictionarySet,dp));
            }
        }
        
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        
        unordered_set<string>dictionarySet(dictionary.begin(),dictionary.end());
        vector<int>dp(n+1,-1);
        return f(0,s,dictionarySet,dp);
        
    }
};