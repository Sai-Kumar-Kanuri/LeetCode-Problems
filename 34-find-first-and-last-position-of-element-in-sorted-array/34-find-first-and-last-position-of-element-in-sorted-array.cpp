class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          int i=0;
        int j=nums.size()-1;
        int mid;
        
        vector<int>result{-1,-1};
        
        while(i<=j)
        {
            mid=(i+j)/2;
            if(nums[mid]>target)
            {
                j=mid-1;
            }
            else if(nums[mid]<target)
            {
                             i=mid+1;
                         }
            else{
                result[0]=mid;
                j=mid-1;
            }
        }
        
        i=0;
        j=nums.size()-1;
        while(i<=j)
        {
            mid=(i+j)/2;
            if(nums[mid]>target)
            {
                j=mid-1;
            }
            else if(nums[mid]<target)
                         {
                             i=mid+1;
                         }
            else{
                result[1]=mid;
                i=mid+1;
            }
        }
        return result;
    }
};