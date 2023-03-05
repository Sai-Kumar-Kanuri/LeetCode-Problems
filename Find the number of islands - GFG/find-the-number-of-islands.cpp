//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        vis[row][col]=1;
        
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size(); 
        int m = grid[0].size();
        
        // int delrow[] = {-1,0,1,0};
        // int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int row1=q.front().first;
            int col1=q.front().second;
            q.pop();
            
            for(int delrow=-1;delrow<=1;delrow++)
            {
                for(int delcol=-1;delcol<=1;delcol++)
                {
                    int nrow=row1+delrow;
                int ncol=col1+delcol;
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
                }
                
            }
            
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m =grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    count++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends