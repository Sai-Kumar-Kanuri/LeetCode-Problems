class Solution {
public:
    bool f(vector<int>& nums,int mid ,int threshold){
        
        double sum=0;
        
        for(auto num : nums){
            sum+=ceil(((double)num/(double)mid));
        }
        
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        
        long long int low=0;
        long long int high=0;
        
        for(int i=0;i<n;i++){
            high+=nums[i];
        }
        long long int ans=high;
        while(low<=high){
            
            long long int mid = (low+high)/2;
            
            if(f(nums,mid,threshold)){
                high=mid-1;
                ans=min(ans,mid);
            }else{
                low=mid+1;
            }
        }
        
        return ans;
        
    }
};