class Solution {
public: 
    unordered_map<char,char>mp;

    bool f(int n){
        string s = to_string(n);

        string rStr = "";
        for(auto it : s){
            if(mp.find(it)!=mp.end()){
                rStr.push_back(mp[it]);
            }else{
                return false;
            }
        }

        return rStr!=s;
    }
    int rotatedDigits(int n) {
        mp['0']='0';
        mp['1']='1';
        mp['8']='8';
        mp['2']='5';
        mp['5']='2';
        mp['6']='9';
        mp['9']='6';

        int ans = 0;

        for(int i=1;i<=n;i++){
            if(f(i)){
                ans++;
            }
        }

        return ans;
    }
};