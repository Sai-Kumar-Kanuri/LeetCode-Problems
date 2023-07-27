class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> indegree(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        // Calculate the indegree of each cell.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int ni = i + drow[k];
                    int nj = j + dcol[k];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                        indegree[ni][nj]++;
                    }
                }
            }
        }
        
        queue<pair<int, int>> q;
        
        // Add all cells with indegree 0 to the queue.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (indegree[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        
        int longestPath = 0;
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + drow[k];
                    int nj = j + dcol[k];
                    
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && matrix[ni][nj] > matrix[i][j]) {
                        indegree[ni][nj]--;
                        if (indegree[ni][nj] == 0) {
                            q.push({ni, nj});
                        }
                    }
                }
            }
            
            longestPath++;
        }
        
        return longestPath;
    }
};
