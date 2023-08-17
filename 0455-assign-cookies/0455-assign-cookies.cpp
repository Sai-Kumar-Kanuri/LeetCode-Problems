class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0;
        int j = 0,ans=0;
        
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int n = g.size();
        int m = s.size();
        while(i<n && j<m){
            if(s[j]>=g[i]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        
        return ans;
    }
};