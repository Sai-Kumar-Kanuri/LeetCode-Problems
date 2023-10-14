class Solution {
public:
    int f(vector<int>& nums, int target,bool flag){
        int low=0;
        int high=nums.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(target<nums[mid]){
                high=mid-1;
            }
            
            else if(target>nums[mid]){
                low=mid+1;
            }
            
            else{
                ans=mid;
                if(flag){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans(2);
        ans[0]=f(nums,target,true);
        ans[1]=f(nums,target,false);
        return ans;
        
    }
};