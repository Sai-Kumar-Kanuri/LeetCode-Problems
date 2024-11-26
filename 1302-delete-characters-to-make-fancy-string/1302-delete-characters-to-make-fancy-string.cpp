class Solution {
public:
    string makeFancyString(string s) {
        
        char prev = s[0];

        string ans = "";

        ans+=s[0];

        int cnt = 1;
        for(int i=1;i<s.length();i++){

            if(prev==s[i]){
                cnt++;
            }else{
                prev=s[i];
                cnt=1;
            }

            if(cnt<3){
                ans+=s[i];
            }
        }

        return ans;
    }
};