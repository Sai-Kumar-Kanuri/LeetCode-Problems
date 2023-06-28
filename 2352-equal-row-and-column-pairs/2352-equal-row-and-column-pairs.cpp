class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        vector<vector<int>>grid2=grid;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=i;j<grid[0].size();j++)
            {
                swap(grid2[i][j],grid2[j][i]);
            }
        }
        
        int ans=0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid2.size();j++)
            {
                if(grid[i]==grid2[j])
                {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};