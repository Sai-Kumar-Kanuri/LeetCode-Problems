class Solution {
public:
    void f(int i,vector<int>& candidates, int target, vector<vector<int>>&ans,vector<int>&temp){
        
        if(i==candidates.size()){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
    
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            f(i,candidates,target-candidates[i],ans,temp);
            temp.pop_back();
        }
        
        f(i+1,candidates,target,ans,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,candidates,target,ans,temp);
        return ans;
    }
};