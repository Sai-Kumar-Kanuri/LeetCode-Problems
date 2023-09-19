class Solution {
public:
    bool isPalindrome(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
    void f(string &s,int start,vector<string>&temp,vector<vector<string>>&ans){
        if(start>=s.length()){
            ans.push_back(temp);
        }
        
        for(int end=start;end<s.length();end++){
            if(isPalindrome(s,start,end)){
                temp.push_back(s.substr(start,end-start+1));
                f(s,end+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        
        vector<string>temp;
        
        f(s,0,temp,ans);
        
        return ans;
    }
};