class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int>freq;
        
        for(auto num : nums){
            freq[num]++;
        }
        
        
        int dominant =0 ;
        int count=0;
        for(auto f : freq){
            
            if(f.second*2>n){
                dominant=f.first;
                count=f.second;
            }
        }
        
        unordered_map<int,int>left_freq;
        
        for(int i=0;i<n;i++){
            if(nums[i]==dominant){
                left_freq[nums[i]]++;
                
                freq[nums[i]]--;
                if(left_freq[nums[i]]*2>i+1 && freq[nums[i]]*2 > n-1-i){
                    return i;
                }
            }
        }
        
        return -1;
        
        
    }
};