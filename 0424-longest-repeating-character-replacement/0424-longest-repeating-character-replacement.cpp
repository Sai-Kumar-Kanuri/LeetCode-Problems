class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0;
        vector<int>freq(26,0);
        int maxFrequency=0;
        int longestSubstringLength=0;
        
        for(int end=0;end<s.size();end++)
        {
            freq[s[end]-'A']++;
            
            maxFrequency=max(maxFrequency,freq[s[end]-'A']);
            bool isValid=((end-start+1-maxFrequency)<=k);
            
            if(!isValid)
            {
                freq[s[start]-'A']--;
                start+=1;
            }
            longestSubstringLength=end-start+1;
        }
        
        return longestSubstringLength;
    }
};