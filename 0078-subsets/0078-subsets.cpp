class Solution {
public:
    void getSubset(vector<int>&nums,vector<int>&set,vector<vector<int>>&subset,int i){
        if(i>=nums.size())
        {
            subset.push_back(set);
            return;
        }
        set.push_back(nums[i]);
        for(auto x:set)
        {
            cout<<x<<" ";
        }
        cout<<endl;
        getSubset(nums,set,subset,i+1);
        set.pop_back();
        getSubset(nums,set,subset,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subset;
        vector<int>set;
        // subset.push_back(set);
        getSubset(nums,set,subset,0);
        return subset;
    }
};