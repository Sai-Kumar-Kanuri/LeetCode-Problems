class Solution {
public:
    void f(vector<int>&inDegree,vector<vector<int>>& requests,int n,int i,int currCount, int& maxCount)
    {
        if(i==requests.size())
        {
            for(int j=0;j<n;j++)
            {
                if(inDegree[j])
                {
                    return;
                }
            }
            maxCount=max(maxCount,currCount);
            return;
        }
       
        
        
            inDegree[requests[i][0]]--;
            inDegree[requests[i][1]]++;
            f(inDegree,requests,n,i+1,currCount+1,maxCount);
            inDegree[requests[i][0]]++;
            inDegree[requests[i][1]]--;
            f(inDegree,requests,n,i+1,currCount,maxCount);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>inDegree(n,0);
        int maxCount=0;
        f(inDegree,requests,n,0,0,maxCount);
        return maxCount;
    }
};