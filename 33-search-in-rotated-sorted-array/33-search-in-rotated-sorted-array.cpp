class Solution {
public:
    
    int binary_search(vector<int>nums,int low,int high,int key)
    {
        if(high<low)
        {
            return -1;
        }
        
        int mid=(low+high)/2;
        if(key==nums[mid])
        {
            return mid;
        }
        
        if(key>nums[mid])
        {
            return binary_search(nums,mid+1,high,key);
        }
       
            return binary_search(nums,low,mid-1,key);
        
    }
    
    int find_pivot(vector<int>nums,int low,int high)
    {
        if(high<low)
        {
            return -1;
        }
        
        if(high==low)
        {
            return low;
        }
        
        int mid=(high+low)/2;
        
        if (mid < high && nums[mid] > nums[mid + 1])
        return mid;
 
    if (mid > low && nums[mid] < nums[mid - 1])
        return (mid - 1);
 
    if (nums[low] >= nums[mid])
        return find_pivot(nums, low, mid - 1);
 
    return find_pivot(nums, mid + 1, high);
    }
    
    int pivoted_binary_search(vector<int>nums,int n,int key)
    {
        int pivot=find_pivot(nums,0,n-1);
        
        if(pivot==-1)
        {
            return binary_search(nums,0,n-1,key);
        }
        
        if(nums[pivot]==key)
        {
            return pivot;
        }
        
        if(nums[0]<=key)
        {
            return binary_search(nums,0,pivot-1,key);
        }
        
        return binary_search(nums,pivot+1,n-1,key);
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return pivoted_binary_search(nums,n,target);
    }
};