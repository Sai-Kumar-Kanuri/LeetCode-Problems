class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string res = "";
        int strLen=0;
        for(int i=0;i<n;i++){
            int l = i;
            int r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if((r - l + 1) > strLen){
                    res = s.substr(l,r-l+1);
                    strLen = r-l+1;  
                }
                l=l-1;
                r=r+1;
            }

            l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if((r - l + 1) > strLen){
                    res = s.substr(l,r-l+1);
                    strLen = r-l+1;  
                }
                l=l-1;
                r=r+1;
            }
        }

       return res;
    }
};