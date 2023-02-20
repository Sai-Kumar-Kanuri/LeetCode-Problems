class Solution {
public:
    int lengthOfLastWord(string s) {
        // vector<vector<char>>ans;
        int count=0;
        int n=s.size();
        int i=n-1;
        while(i>=0 && s[i]==' '){
            i--;
        }
        
        while(i>=0 && s[i]!=' '){
            i--;
            count++;
        }
        return count;
        
        return 0;
        
    }
};