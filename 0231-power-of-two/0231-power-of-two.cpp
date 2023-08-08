class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0) return false;
        
        for(int i=31;i>=0;i--){
            if(1<<i == n){
                return true;
            }
        }
        
        return false;
    }
};