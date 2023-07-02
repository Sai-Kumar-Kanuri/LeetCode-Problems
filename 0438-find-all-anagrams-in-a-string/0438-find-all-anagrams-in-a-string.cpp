class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        
        vector<int>mp1(26,0),mp2(26,0);
        vector<int>ans;
        
        for(auto &it:p)
        {
            mp1[it-'a']++;
        }
        int j=0,i=0;
        
        while(j<s.size())
        {
            mp2[s[j]-'a']++;
            
            if(j-i+1==p.size())
            {
                if(mp1==mp2){
                    ans.push_back(i);
                }
                
                mp2[s[i]-'a']--;
                i++,j++;
            }
            else{
                j++;
            }
        }
        
        return ans;
    }
};