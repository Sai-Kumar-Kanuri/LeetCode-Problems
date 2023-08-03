class Solution {
public:
    bool isGood(vector<int>& nums) {
        
        int size = nums.size();
        
        int maxi = *max_element(nums.begin(),nums.end());
        
        unordered_map<int,int>mp_base;
        unordered_map<int,int>mp;
        for(int i=1;i<=maxi;i++){
            if(i==maxi){
                mp_base[i]=2;
            }
            
            else{
                mp_base[i]++;
            }
        }
        
        
        for(auto num : nums){
            mp[num]++;
        }
        
        for(int i=1;i<=maxi;i++){
            if(mp[i]!=mp_base[i]){
                return false;
            }
        }
        
        return true;
        
    }
};