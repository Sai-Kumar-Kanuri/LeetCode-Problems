class Solution {
public:
    void getPermutation(vector<int>&nums,int i,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            // temp.push_back(nums[j]);
            swap(nums[i],nums[j]);
            getPermutation(nums,i+1,ans);
            swap(nums[i],nums[j]);
            // temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getPermutation(nums,0,ans);
        
        return ans;
    }
};