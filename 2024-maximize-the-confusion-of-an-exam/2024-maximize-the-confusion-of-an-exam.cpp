class Solution {
public:
    int f(string answerKey,int k,char ch) {
        
        int left=0,right=0;
        int maxi=0;
        int ch_cnt=0;        
        for(int right=0;right<answerKey.size();right++){
            
            if(answerKey[right]==ch){
                ch_cnt++;
            }
            
            while(left<answerKey.size() && ch_cnt>k){
                if(answerKey[left]==ch){
                    ch_cnt--;
                }
                left++;
            }
            maxi=max(maxi,right-left+1);
        }
        
        return maxi;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int maxt=f(answerKey,k,'T');
        int maxf=f(answerKey,k,'F');
        cout<<maxt<<" "<<maxf<<endl;
        return max(maxt,maxf);
    }
};