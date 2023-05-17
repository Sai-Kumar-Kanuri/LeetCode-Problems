class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0, ans = nums[0];
        int n = nums.size();
        for(int i=0; i<n; i++)
            ans = max(ans, nums[i]);

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(sum < 0)
                sum = 0;
            else{
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};