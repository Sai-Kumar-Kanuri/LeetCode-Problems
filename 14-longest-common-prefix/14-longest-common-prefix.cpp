class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       sort(strs.begin(),strs.end());
        int n=strs.size(),i=0;
        int minlen = min(strs[0].size(),strs[n-1].size());
        string first = strs[0];
        string last= strs[n-1];
        while(i<minlen && first[i]==last[i])
        {
            i++;
        }
        string strpre=first.substr(0,i);
        return strpre;
    }
    // int min(int m,int n)
    // {
    //     if(m<n) return m;
    //     else return n;
    // }
};