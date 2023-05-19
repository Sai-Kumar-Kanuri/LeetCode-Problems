class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        queue<pair<int,int>>q;
        
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                auto node=q.front();
            
                q.pop();
                int x=node.first;
                int y=node.second;

                 if((x==0 or y==0 or x==n-1 or y==m-1)){
                        if((x!=entrance[0] or y!=entrance[1]))
                            return steps;
                    }

                for(int i=0;i<4;i++)
                {
                    int nrow=x+drow[i];
                    int ncol=y+dcol[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol]!='+')
                    {
                        maze[nrow][ncol]='+';
                        q.push({nrow,ncol});
                    }
                }
            }
            steps++;
            
        }
        return -1;
    }
};