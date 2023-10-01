class Solution {
public:
    string reverseWords(string s) {
        
        string str="";
        vector<string>ans;
        for(int i=0;i<s.size();i++){
            
            if(s[i]==' '){
                ans.push_back(str);
                str="";
            }else{
                str+=s[i];
            }
        }
        
        ans.push_back(str);
        
        string a = "";
        
        for(auto it:ans){
            cout<<it<<endl;
            reverse(it.begin(),it.end());
            a+=it;
            a+=" ";
        }
        
        a.pop_back();
        
        return a;
        
    }
};