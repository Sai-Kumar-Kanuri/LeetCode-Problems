class Solution {
public:
    bool f(vector<int>&nums,int diff,int x){
        
        set<int>res;
        int n = nums.size();
        for(int i=n-1-x;i>=0;i--){
            res.insert(nums[i+x]);
            
            auto it = res.lower_bound(nums[i]);
            
            if(it==res.begin()){
                if(abs(*it-nums[i])<=diff){
                    return true;
                }
            }else{
                if(abs(*it-nums[i])<=diff){
                    return true;
                }
                it--;
                if(abs(*it-nums[i])<=diff){
                    return true;
                }
            }
        }
        return false;

    }
    int minAbsoluteDifference(vector<int>& nums, int x) {
        
        int n = nums.size();
        // int mini=INT_MAX;
        // for(int i=0;i<n-x;i++){
        //     for(int j=i+x;j<n;j++){
        //         mini=min(abs(nums[i]-nums[j]),mini);
        //     }
        // }
        
        int low=0;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(f(nums,mid,x)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;;
    }
};