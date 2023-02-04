class Solution {
public:
    bool f(vector<int>&s1,vector<int>&s2){
        for(int i=0;i<26;i++){
            if(s1[i]!=s2[i]){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        
        vector<int>freqS1(26,0);
        for(auto x:s1){
            freqS1[x-'a']++;
        }
        
        vector<int>freqS2(26,0);
        int i=0,j=0;
        
        while(j<s2.size()){
            freqS2[s2[j]-'a']++;
            
            
            if(j-i+1==s1.size()){
                if(f(freqS1,freqS2)){
                    return true;
                }
            }
            
            if(j-i+1<s1.size()){
                j++;
            }
            
            else{
                freqS2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;

    }
};