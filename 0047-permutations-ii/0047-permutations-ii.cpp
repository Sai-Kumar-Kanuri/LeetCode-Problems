class Solution {
public:
    void getPermutation(vector<int>&nums,int i,set<vector<int>>&ans){
        if(nums.size()==i){
            ans.insert(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            getPermutation(nums,i+1,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>ans;
        getPermutation(nums,0,ans);
        vector<vector<int>>res;
        for(auto x: ans){
            res.push_back(x);
            }
        return res;
    }
};