class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            min_heap.push({cnt,i});
        }
        
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        
        
        return ans;
        
        
    }
};