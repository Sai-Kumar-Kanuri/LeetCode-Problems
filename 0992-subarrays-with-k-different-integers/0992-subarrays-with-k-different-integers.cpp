class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
        
    int f(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left=0;
        int right=0;
        int ans=0;
        
        while(right<nums.size()){
            mp[nums[right]]++;
            
            while(mp.size()>k){
                mp[nums[left]]--;
                
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            
            if(mp.size()<=k){
                ans+=right-left+1;
            }
            
            right++;
        }
        
        return ans;
    }
};