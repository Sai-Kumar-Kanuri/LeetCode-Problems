class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        int ans=0,sum=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum++;
            }else{
                sum--;
            }
            if(sum==0){
                ans=i+1;
            }else if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
            
        }
        
        return ans;
    }
};