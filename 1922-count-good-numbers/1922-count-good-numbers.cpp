class Solution {
public:
    int p=1e9 + 7;
    long long checkNumbers(long long x,long long y){
        long long res=1;
        
        x=x%p;
        if(x==0){
            return 0;
        }
        while(y>0){
        if(y&1){
            res=(res*x)%p;
        }    
            
            y=y>>1;
            x=(x*x)%p;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long prime_count=n/2;
        long long even_count= n-prime_count;
long long ans=((checkNumbers(4LL,prime_count)%p)*((checkNumbers(5LL,even_count)))%p)%p;
        return ans;
    }
};