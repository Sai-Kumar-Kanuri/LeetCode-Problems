class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        
        
        int left=0;
        
        int ans=0;
        
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.length();j++){
                 mp[s[j]]++;

                bool valid = false;
                for (auto it : mp) {
                    if (it.second >= k) {
                        valid = true;
                        break;
                    }
                }
                
                if (valid) {
                    ans++;
                }
            }
            
            
        }
        
        return ans;
    }
};