class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini=1e9;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                mini=min(mini,abs(i-start));
            }
        }
        return mini;
    }
};