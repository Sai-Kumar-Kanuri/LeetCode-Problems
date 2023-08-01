class Solution {
public:
    
    void f(int idx,int n, int k, vector<vector<int>>&ans, vector<int>&temp){
        
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx;i<=n;i++){
            temp.push_back(i);
            f(i+1,n,k,ans,temp);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(1,n,k,ans,temp);
        return ans;
    }
};