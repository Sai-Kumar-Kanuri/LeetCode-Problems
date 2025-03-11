class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>mp;

        int left=0,right=0;
        int n=s.size();
        int count=0;
        while(right<s.size()){

            mp[s[right]]++;

            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){

                count+= (n-right);
                mp[s[left]]--;
                left++; 
            }

            right++;

        }

        return count;
    }
};