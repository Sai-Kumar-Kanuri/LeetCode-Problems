class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,subarr=0;
        
        for(auto num:nums)
        {
            if(num==0)
            {
                subarr+=1;
            }
            
            else{
                subarr=0;
            }
            
            ans+=subarr;
        }
        return ans;
    }
};