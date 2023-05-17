class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int k=n-1;
        
        int max_prod=INT_MIN;
        
        int prefix=1,suffix=1;
        
        for(int i=0;i<n;i++)
        {
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            prefix*=nums[i];
            
            suffix*=nums[k-i];
            
            
            max_prod=max(max_prod,max(prefix,suffix));
        }
        
        return max_prod;
        
    }
};