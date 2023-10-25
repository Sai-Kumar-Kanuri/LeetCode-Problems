class Solution {
public:
    int kthGrammar(int n, int k) {
        
        int curr =0;
        int left = 0;
        int right = pow(2,n-1);

        for(int i=0;i<n-1;i++){
            int mid = (left + right)/2;

            if(k<=mid){
                right=mid;
            }else{
                left=mid+1;
                curr = curr==0 ? 1 : 0;
            }
        }

        return curr;
    }
};