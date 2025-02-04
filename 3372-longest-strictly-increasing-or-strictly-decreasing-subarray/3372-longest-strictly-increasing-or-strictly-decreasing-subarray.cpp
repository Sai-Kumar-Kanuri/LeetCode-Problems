class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int ans = 1;
        int inc=1;
        int dec=1;
        for(int i=1;i<nums.size();i++){

            if(nums[i-1]<nums[i]){
                inc+=1;
            }else{
                inc=1;
            }

            ans=max(ans,inc);

            if(nums[i-1]>nums[i]){
                dec+=1;
            }else{
                dec=1;
            }

            ans=max(ans,dec);
        }

        return ans;
    }
};