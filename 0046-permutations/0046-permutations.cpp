class Solution {
public:
    void f(int index,vector<vector<int>>&ans,vector<int>& nums){
        
        if(index==nums.size()){
            ans.push_back(nums);
            return ;
        }
        
        
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            f(index+1,ans,nums);
            swap(nums[index],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>ans;
        f(0,ans,nums);
        return ans;
        
    }
};