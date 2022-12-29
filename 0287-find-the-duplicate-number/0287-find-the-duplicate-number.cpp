class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        while(i<nums.size())
        {
            int correct = nums[i]-1;
            if(nums[i]!=nums[correct])
            {
                swap(nums[i],nums[correct]);
            }
            else{
                i++;
            }
        }
        
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                break;
            }
        }
        return nums[i];
    }
};