class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int low=0;
        int high=nums.size();
        
        if(target>nums[high-1]){
            return high;
        }
        
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(nums[mid]==target){
                return mid;
            }
            
            if(target>nums[mid]){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        return low;
        
        
    }
};