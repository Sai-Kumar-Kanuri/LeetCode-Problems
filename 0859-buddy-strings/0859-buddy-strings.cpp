class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.size()!=goal.size())
        {
            return false;
        }
        
        if(s==goal)
        {
            vector<int>freq(26,0);
            
            for(auto& ch:s)
            {
                freq[ch-'a']+=1;
                if(freq[ch-'a']==2)
                {
                    return true;
                }
            }
            
            return false;
        }
        
        int findex=-1;
        int sindex=-1;
        
        for(int i=0;i<s.size();++i)
        {
            if(s[i]!=goal[i])
            {
                if(findex==-1)
                {
                    findex=i;
                }
                
                else if(sindex==-1)
                {
                    sindex=i;
                }
                
                else{
                    return false;
                }
            }
        }
        
        if(sindex==-1)
        {
            return false;
        }
        
        return s[findex]==goal[sindex] && s[sindex]==goal[findex];
        
    }
};