class Solution {
public:
    void f(vector<int>&nums,int i,vector<int>subset,vector<vector<int>>&subsets){

        if(i==nums.size()){
            subsets.push_back(subset);
            return;
        }


        subset.push_back(nums[i]);
        f(nums,i+1,subset,subsets);

        subset.pop_back();
        f(nums,i+1,subset,subsets);
    }


    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>subsets;

        f(nums,0,{},subsets);
        
        int ans=0;

        for(auto subset:subsets){
            int xorr = 0;

            for(auto it:subset){
                xorr^=it;
            }

            ans+=xorr;
        }

        return ans;
    }
};