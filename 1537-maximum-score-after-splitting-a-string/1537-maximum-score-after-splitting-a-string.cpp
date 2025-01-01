class Solution {
public:
    int maxScore(string s) {

        int z_cnt=0;
        
        int o_cnt = count(s.begin(),s.end(),'1');

        int ans=0;

        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='1'){
                o_cnt--;
            }else{
                z_cnt++;
            }

            ans=max(ans,o_cnt+z_cnt);
        }

        return ans;
        
    }
};