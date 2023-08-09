class Solution {
public:
    int f(vector<int>&nums,int t){
        int k=0;
        int cnt=0;
        while(k<nums.size()-1){
            if(nums[k+1]-nums[k]<=t){
                cnt++;
                k++;
            }
            k++;
        }
        return cnt;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int left=0;
        int right = nums[n-1]-nums[0];
        int ans=0;
        while(left<=right){
            int mid = (left+right)/2;
            
            if(f(nums,mid)>=p){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        
        return ans;
    }
};