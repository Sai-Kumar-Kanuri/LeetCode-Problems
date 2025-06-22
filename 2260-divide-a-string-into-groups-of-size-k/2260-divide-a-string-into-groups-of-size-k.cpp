class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        vector<string>ans;

        int i=0;

        int cnt = 0;
        
        while(i<s.length()){

            string str = "";

            while(cnt<k && i<s.length()){
                str+=s[i];
                i++;
                cnt++;
            }

            while(i==s.length() && cnt<k){
                str+=fill;
                cnt++;
            }

            ans.push_back(str);

            cnt=0;
        }

        return ans;
    }
};