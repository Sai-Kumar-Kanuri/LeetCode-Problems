class Solution {
public:
    void get_combination(int index,int target,vector<int>& candidates,vector<vector<int>>&result,vector<int>&inner)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
                result.push_back(inner);
            }
            return;
        }
        
        if(candidates[index]<=target)
        {
            inner.push_back(candidates[index]);
            get_combination(index,target-candidates[index],candidates,result,inner);
            inner.pop_back();
        }  
            get_combination(index+1,target,candidates,result,inner);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> inner;
        get_combination(0,target,candidates,result,inner);
        return result;
    }
};