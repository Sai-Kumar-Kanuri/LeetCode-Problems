class Solution {
public:
    int findSum(int n)
    {
        int sum=0;
        
        while(n>0)
        {
            int x=n%10;
            sum+=x*x;
            n=n/10;
        }
        
        return sum;
    }
    bool isHappy(int n) {
        
        set<int>s;
        
        while(n!=1 && !s.count(n))
        {
            s.insert(n);
            n=findSum(n);
        }
        
        return n==1;
    }
};