class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
        unordered_map<char,char>mp2;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(mp1[s[i]] && mp1[s[i]]!=t[i]) return false;
            if(mp2[t[i]] && mp2[t[i]]!=s[i]) return false;
            
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        
        return true;
        
    }
};