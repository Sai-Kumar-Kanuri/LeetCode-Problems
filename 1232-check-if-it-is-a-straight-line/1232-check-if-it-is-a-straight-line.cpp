class Solution {
public:
    int getDiffX(vector<int>&a,vector<int>&b)
    {
        return a[0]-b[0];
    }
    
    int getDiffY(vector<int>&a,vector<int>&b)
    {
        return a[1]-b[1];
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dy = getDiffY(coordinates[1],coordinates[0]);
        int dx = getDiffX(coordinates[1],coordinates[0]);
        
        int n= coordinates.size();
        for(int i=2;i<n;i++)
        {
            if(dy*getDiffX(coordinates[i],coordinates[0])!=dx*getDiffY(coordinates[i],coordinates[0]))
            {
                return false;
            }
            continue;
        }
        
        return true;
    }
};