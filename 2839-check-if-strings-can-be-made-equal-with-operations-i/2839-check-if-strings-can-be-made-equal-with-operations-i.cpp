class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1==s2){
            return true;
        }
        for(int i=0;i<=1;i++){
            char temp=s1[i];
            s1[i]=s1[i+2];
            s1[i+2]=temp;
            cout<<s1<<" "<<s2<<endl;
            if(s1==s2){
                return true;
            }
        }
        
        for(int i=0;i<=1;i++){
            char temp=s2[i];
            s2[i]=s2[i+2];
            s2[i+2]=temp;
            cout<<s1<<" "<<s2<<endl;
            if(s1==s2){
                return true;
            }
        }
        
        return false;
    }
};