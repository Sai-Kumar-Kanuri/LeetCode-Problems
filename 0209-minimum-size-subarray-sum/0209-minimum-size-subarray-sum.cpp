class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0;
        int end=0;
        int n=nums.size();
        int curr_sum=0;
        int min_len=INT_MAX;
        
        for(end=0;end<n;end++)
        {
            curr_sum+=nums[end];
            
            while(curr_sum>=target && start<=end)
            {
                curr_sum-=nums[start];
                min_len=min(min_len,end-start+1);
                start++;
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};