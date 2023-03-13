class Solution {
public:
    bool f(int i,int j,string s,string t)
    {
        if(i==s.length())
        {
            return true;
        }
        
        if(j==t.length())
        {
            return false;
        }
        
        if(s[i]==t[j])
        {
            return f(i+1,j+1,s,t);
        }
        
        return f(i,j+1,s,t);
    }
    bool isSubsequence(string s, string t) {
        
        return f(0,0,s,t);
    }
};