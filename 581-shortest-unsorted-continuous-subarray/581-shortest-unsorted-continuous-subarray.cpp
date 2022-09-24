class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<nums.size()-1 && nums[low]<=nums[low+1])
        {
            low++;
        }
        if(low==(nums.size()-1))
        {
            return 0;
        }
        while(high>=0 && nums[high]>=nums[high-1])
        {
            high--;
        }
        int max_array=INT_MIN;
        int min_array=INT_MAX;
        for(int i=low;i<=high;i++)
        {
            max_array=max(max_array,nums[i]);
            min_array=min(min_array,nums[i]);
            // cout<<max_array<<" "<<min_array<<endl;
        }
        
        cout<<max_array<<" "<<min_array<<endl;
        
        cout<<high<<" "<<low<<endl;
        
        while(low>0 && nums[low-1]>min_array)
        {
            low--;
        }
        
        while(high<(nums.size()-1) && nums[high+1]<max_array)
        {
            high++;
        }
        
        vector<int>v;
        
        for(int i=low;i<=high;i++)
        {
            v.push_back(nums[i]);
        }
        
        return v.size();
    }
};