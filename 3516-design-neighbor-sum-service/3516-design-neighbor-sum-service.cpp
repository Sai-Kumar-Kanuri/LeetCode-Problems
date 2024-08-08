class neighborSum {
public:
    vector<vector<int>>grid;
    int n;

    neighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
    }
    
    int adjacentSum(int value) {

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        int sum =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==value){
                    for(int k=0;k<4;k++){
                        int r = i + dr[k];
                        int c = j + dc[k];
                        if(r>=0 && r<n && c>=0 && c<n){
                            sum+=grid[r][c];
                        }
                    }
                }
            }
        }

        return sum;
    }
    
    int diagonalSum(int value) {
        int sum =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==value){
                    if(i-1>=0 && j-1>=0){
                        sum+=grid[i-1][j-1];
                    }

                    if(i+1<n && j-1>=0){
                        sum+=grid[i+1][j-1];
                    }

                    if(i-1>=0 && j+1<n){
                        sum+=grid[i-1][j+1];
                    }

                    if(i+1<n && j+1<n){
                        sum+=grid[i+1][j+1];
                    }
                }
            }
        }

        return sum;      
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */