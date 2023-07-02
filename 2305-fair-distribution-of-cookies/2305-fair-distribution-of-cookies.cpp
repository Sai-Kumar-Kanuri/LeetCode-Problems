class Solution {
public:
    int f(vector<int>& cookies,vector<int>&child,int i,int max_val)
    {
        if(i==cookies.size())
        {
            return max_val;
        }
        
        int ans=1e8;
        
        for(int j=0;j<child.size();j++)
        {
            child[j]+=cookies[i];
            ans=min(ans,f(cookies,child,i+1,max(max_val,child[j])));
            child[j]-=cookies[i];

        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        vector<int>child(k,0);
        
        return f(cookies,child,0,0);
    }
};