class Solution {
public:
    int f(vector<int>&nums,int maxSum){
        int partitions=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=maxSum){
                sum+=nums[i];
            }else{
                partitions++;
                sum=nums[i];
            }
        }
        
        return partitions;
    }
    int splitArray(vector<int>& nums, int k) {
        int high=0;
        for(auto num:nums){
            high+=num;
        }
        int low=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            int paritions = f(nums,mid);
            if(paritions<=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};