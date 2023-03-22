class Solution {
public: 
    int m,n,mod = 1e9+7;
    long long dp_max[20][20], dp_min[20][20];
    long long rec1(int x, int y, vector<vector<int>>&g){
        if(x ==m-1 && y == n-1)
            return g[m-1][n-1];
        
        if(dp_max[x][y] != LLONG_MIN)
            return dp_max[x][y];
        
        long long ans = -1e18;
        if(x < m - 1)
            ans = max({ans,g[x][y]*rec1(x+1, y, g), g[x][y]*rec2(x+1,y,g)});
        if(y < n -1)
            ans = max({ans, g[x][y]*rec1(x,y+1,g), g[x][y]*rec2(x,y+1,g)});
        
        return dp_max[x][y] = ans;
    }
    
    long long rec2(int x, int y, vector<vector<int>>&g){
        if(x ==m-1 && y == n-1)
            return g[m-1][n-1];
        
        if(dp_min[x][y] != LLONG_MAX)
            return dp_min[x][y];
        
        long long ans = 1e18;
        if(x < m - 1)
            ans = min({ans,g[x][y]*rec1(x+1, y, g), g[x][y]*rec2(x+1,y,g)});
        if(y < n -1)
            ans = min({ans, g[x][y]*rec1(x,y+1,g), g[x][y]*rec2(x,y+1,g)});
        
        return dp_min[x][y] = ans;
    }
    
    int maxProductPath(vector<vector<int>>& g) {
        m = g.size();
        n = g[0].size();
        for(int i=0;i<m;i++)
            for(int j = 0;j<n;j++){
                dp_max[i][j] = LLONG_MIN;
                dp_min[i][j] = LLONG_MAX;
            }
        
        if(rec1(0,0,g) < 0)
            return -1;
        return rec1(0,0,g)%mod;
    }
};