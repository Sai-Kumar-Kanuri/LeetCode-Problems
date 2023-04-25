class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        
        int i=0,j=0;
        string res="";
        while(i<m || j<n)
        {
            if(i<m)
            {
                res.push_back(word1[i++]);
            }
            if(j<n)
            {
                res.push_back(word2[j++]);
            }
        }
        return res;
    }
};