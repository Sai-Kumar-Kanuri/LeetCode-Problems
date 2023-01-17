class Solution {
public:
//     void getCombination(vector<int>&candidates,int target,int i,vector<vector<int>>&ans,vector<int>&arr){
//         if(target==0){
//             ans.push_back(arr);
//             return;
//         }
        
//         for(int j=i;j<candidates.size();j++){
//             if(j>i && candidates[j]==candidates[j-1]) continue;
//             if(candidates[j]>target) break;
            
//             arr.push_back(candidates[j]);
//             getCombination(candidates,target-candidates[j],i+1,ans,arr);
//             arr.pop_back();
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         vector<vector<int>>ans;
//         vector<int>arr;
//         getCombination(candidates,target,0,ans,arr);
//         return ans;
//     }
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}

};