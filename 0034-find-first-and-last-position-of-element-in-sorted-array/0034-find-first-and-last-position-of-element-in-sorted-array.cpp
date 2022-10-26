class Solution {
public:
    
    int searchIndex(vector<int>&nums,int target,bool findStartIndex)
    {
         int start=0;
        int ans=-1;
        int end=nums.size()-1;
        
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            
            if(target<nums[mid])
            {
                end=mid-1;
            }
            
            else if(target>nums[mid]){
                start=mid+1;
            }
            else{
                ans=mid;
                if(findStartIndex)
                {
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int>ans(2,-1);
        
        ans[0]=searchIndex(nums,target,true);
        ans[1]=searchIndex(nums,target,false);
        
        return ans;
    }
};