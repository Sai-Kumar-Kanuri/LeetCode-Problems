class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch=='A' || ch =='E' || ch =='I' || ch == 'O' || ch == 'U'){
            return true;
        }
        return false;
    }
    string sortVowels(string s) {
        
        string str = "";
        
        for(auto c: s){
            if(isVowel(c)){
                str+=c;
            }
        }
        
        sort(str.begin(),str.end());
        
        int j=0;
        
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=str[j];
                j++;
            }
        }
        
        return s;
        
        
    }
};