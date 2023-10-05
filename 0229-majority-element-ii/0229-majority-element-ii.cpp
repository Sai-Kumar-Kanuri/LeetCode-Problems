class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        map<int,int> mp;
        
        for(auto it:nums){
            mp[it]++;
        }
        
        int n = nums.size();
        int count = n/3;
        vector<int>ans;
        for(auto it : mp){
            if(it.second>count){
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
    }
};