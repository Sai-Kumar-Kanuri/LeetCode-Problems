class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0,x;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
               break;
            }
        }
        // if(nums[n-1]!=n)
        // {
        //     return n;
        // }
        return i;
    }
};