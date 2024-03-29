class Solution {
public:
    int maxVowels(string s, int k) {

        unordered_set<char> vowels{'a','e','i','o','u'};
        
        int count=0;
        for(int i=0;i<k;i++)
        {
            count+=vowels.count(s[i]);
        }
        
        int ans=count;
        
        for(int i=k;i<s.length();i++)
        {
            count+=vowels.count(s[i])-vowels.count(s[i-k]);
            ans=max(ans,count);
        }
        
        return ans;
    }
};