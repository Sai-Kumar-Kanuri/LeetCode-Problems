class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left=0,right=0;
        int totalSum=0;
        
        for(auto it:nums){
            totalSum+=it;
        }
        
        int target = totalSum-x;
        
        int currSum=0,maxi=-1;
        
        
        for(right=0;right<nums.size();right++){
            currSum+=nums[right];
            
            while(left<=right && currSum>target){
                currSum-=nums[left];
                left++;
            }
            
            if(currSum==target){
                maxi=max(maxi,right-left+1);
            }
        }
        
        return maxi==-1 ? -1 : nums.size()-maxi;
    }
};