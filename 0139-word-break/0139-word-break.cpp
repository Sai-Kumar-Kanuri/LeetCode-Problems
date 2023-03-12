class Solution {
public:
    bool f(int i,int j,set<string>&sub,string s,vector<vector<int>>&dp)
    {
        if(i==s.length() && j==s.length())
        {
            return true;
        }
        
        if(i>=s.length() || j>=s.length())
        {
            return false;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        string str;
        for(int k=i;k<=j;k++)
        {
            str+=s[k];
        }
        
        if(sub.find(str)!=sub.end())
        {
            bool x=f(j+1,j+1,sub,s,dp);
            bool y=f(i,j+1,sub,s,dp);
            
            return dp[i][j]=x||y;
        }
        else{
            return dp[i][j]=f(i,j+1,sub,s,dp);
        }
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>sub;
        
        for(auto it: wordDict)
        {
            cout<<it<<endl;
            sub.insert(it);
        }
        
        int n=s.length();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        return f(0,0,sub,s,dp);
    }
};