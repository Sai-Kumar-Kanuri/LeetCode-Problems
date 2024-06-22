class Solution {
public:
    int f(vector<int>& nums, int k) {
        
        int left=0;
        int right=0;
        int odd=0;
        int count=0;
        for(right=0;right<nums.size();right++){
            if(nums[right]&1){
                odd++;
            }

            while(odd>k){
                if(nums[left]&1){
                    odd--;
                }
                left++;
            }

            count+=right-left+1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return f(nums,k)-f(nums,k-1);
    }


    
};