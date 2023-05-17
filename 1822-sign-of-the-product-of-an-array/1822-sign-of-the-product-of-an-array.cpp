class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        for(auto x:nums)
        {
            if(x<0)
            {
                count++;
            }
            
            else if(x==0)
            {
                return 0;
            }
        }
        
        
        if(count%2==0)
        {
            return 1;
        }
        
        return -1;
    }
};