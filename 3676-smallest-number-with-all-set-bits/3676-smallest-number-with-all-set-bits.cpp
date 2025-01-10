class Solution {
public:
    int smallestNumber(int n) {

        int cnt=0;

        while(n>0){
            n=n>>1;
            cnt++;
        }

        double result = pow(2, cnt);

        return result-1;        
    }
};