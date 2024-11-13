class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();

        if (k * 2 > n) return false;

        for(int i=0;i<=n-2*k;i++){
            bool increasing1=true,increasing2 = true;
            for(int j=i+1;j<i+k;j++){
                if(nums[j]<=nums[j-1]){
                    increasing1=false;
                    break;
                }
            }

            if(increasing1){
                for(int j=i+k+1;j<i+2*k;j++){
                    if(nums[j]<=nums[j-1]){
                        increasing2=false;
                        break;
                    }
                }
            }

            if(increasing1 && increasing2){
                return true;
            }
        }

        return false;
    }
};