class Solution {
public:
    int reverse(int x) {
        
        long r=0;
        while(x){
            long m = x%10;
            r=r*10+m;
            x=x/10;
        }
        if(r>INT_MAX || r<INT_MIN) return 0;
        
        return int(r);
    }
};