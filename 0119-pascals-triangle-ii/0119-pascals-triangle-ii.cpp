class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<vector<int>>result(numRows+1);
        
        for(int i=0;i<numRows+1;i++)
        {
            result[i].resize(i+1);
            result[i][0]=result[i][i]=1;
            
            for(int j=1;j<i;j++)
            {
                result[i][j]=result[i-1][j-1]+result[i-1][j];
            }
        }
        
        return result[numRows];
    }
};