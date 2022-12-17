class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                nums[flag]=nums[i];
                flag++;
            }
        }
        return flag;
    }
};