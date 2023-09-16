class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        
        int pivot = -1;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                pivot = i;
                break;
            }
        }
        
        if(pivot==-1){
            return 0;
        }
        
        for(int i=pivot+1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                return -1;
            }
        }
        
        
        if(nums[nums.size()-1]>nums[0]){
            return -1;
        }
        
        return nums.size()-pivot;
        
    
        
    }
};