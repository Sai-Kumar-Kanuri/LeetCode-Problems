class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        
        vector<int>prefix_n(n+1,0);
        vector<int>postfix_y(n+1,0);
        
        for(int i=1;i<=n;i++){
            prefix_n[i]=prefix_n[i-1];
            if(customers[i-1]=='N'){
                prefix_n[i]+=1;
            }
        }
        
        for(int i=n-1;i>=0;i--){
            postfix_y[i]=postfix_y[i+1];
            if(customers[i]=='Y'){
                postfix_y[i]+=1;
            }
        }
        
        int minPenalty=1e9;
        int idx=0;
        for(int i=0;i<n+1;i++){
            int curPenalty=prefix_n[i]+postfix_y[i];
            
            if(curPenalty<minPenalty){
                minPenalty=curPenalty;
                idx=i;
            }
        }
        
        return idx;
    }
};