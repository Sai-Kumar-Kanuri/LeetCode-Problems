class Solution {
public:
    int totalMoney(int n) {
        
        int ans = 0;
        int initial_money =1;
        
        while(n>0){
            for(int i=0;i<min(n,7);i++){
                ans+=initial_money+i;
            }
            
            n=n-7;
            initial_money++;
        }
        return ans;
    }
};