class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int>mp1;
        
        for(auto it : chars){
            mp1[it]++;
        }
        
        int ans=0;
        
        for(auto word:words){
            
            unordered_map<char,int>mp2;
            
            for(auto it: word){
                mp2[it]++;
            }
            
            bool flag=true;
            
            for(auto it: mp2){
                if(mp1[it.first]<it.second){
                    flag=false;
                    break;
                }
            }
            
            if(flag){
                ans+=word.size();
            }
        }
        
        return ans;
    }
};