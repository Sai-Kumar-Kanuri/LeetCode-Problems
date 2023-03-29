class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        vector<int>nums1(nums.begin(),nums.end());
        
        sort(nums.begin(),nums.end());
        sort(nums1.begin(),nums1.end());
        
        int cnt=0,i=0,j=0;
        
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]==nums[j])
            {
                i++;
            }
            
            else{
                i++;
                j++;
                cnt++;
            }
        }
        
        return cnt;
        
    }
};