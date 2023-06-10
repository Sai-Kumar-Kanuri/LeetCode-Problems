class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int count=0;
        for(auto arr:grid)
        {
            for(auto element : arr)
            {
                if(element<0)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};