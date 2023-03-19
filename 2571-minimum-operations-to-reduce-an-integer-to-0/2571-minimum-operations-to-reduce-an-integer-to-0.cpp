class Solution {
public:
    int f(int n)
    {
        
        
        if(n<=0)
        {
            return 0;
        }
        
        if(n==1)
        {
            return 1;
        }
        
        int i=1;
        
       while(i*2<n)
       {
           i=i*2;
       }
        
        int l=f(n-i);
        int r=f(i*2-n);
        
        return min(l,r)+1; 
        
    }
    
    int minOperations(int n) {
        
        return f(n);
        
    }
};