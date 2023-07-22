class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2},
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1}
        };
        vector<vector<double>>curr(n,vector<double>(n,0));
        vector<vector<double>>next(n,vector<double>(n,0));
        
        
        curr[row][column]=1;
        
        
        for(int moves=0;moves<k;moves++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    next[i][j]=0;
                        for(auto it:directions){
                            int ni=i+it.first;
                            int nj=j+it.second;
                            
                            if(ni>=0 && ni<n && nj>=0 && nj<n){
                                next[i][j]+=(curr[ni][nj]/8.0);
                            }
                        }   
                }
            }
            curr.swap(next);
        }
        
        double totalProbability = 0;
        for (const auto& row : curr) {
            for (const auto& cell : row) {
                totalProbability += cell;
            }
        }
        return totalProbability;
    }
};