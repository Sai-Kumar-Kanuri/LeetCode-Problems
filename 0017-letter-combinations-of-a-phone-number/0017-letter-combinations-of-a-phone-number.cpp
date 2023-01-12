unordered_map<char, string> L({{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}});
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int len = digits.size();
        if(len==0) return ans;
        getCombinations(0,len,ans,digits,"");
        return ans;
    }
    void getCombinations(int i,int &len,vector<string>&ans,string &digits,string str){
        if(i==len){
            cout<<str<<" ";
            ans.push_back(str);
        }
        
        else{
            string letters=L[digits[i]];
            for(int j=0;j<letters.size();j++)
            {
                // cout<<letters<<endl;
                getCombinations(i+1,len,ans,digits,str+letters[j]);
            }
        }
    }
};