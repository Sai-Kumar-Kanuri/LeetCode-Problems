class Solution {
public:
    vector<int> generateTriangle(int row){
        vector<int>temp;
        long long ans=1;
        temp.push_back(1);
        
        for(int col=1;col<row;col++){
            ans = ans*(row-col);
            ans/=col;
            temp.push_back(ans);
        }
        
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        
        for(int i=1;i<=numRows;i++){
            res.push_back(generateTriangle(i));
        }
        
        return res;
    }
};