class Solution {
public:
    
    int find(vector<vector<int>>& rides,int start,int tofind)
    {
        int low=start;
        int end=rides.size()-1;
        int ans=-1;
        while(low<=end)
        {
            int mid=(low+end)/2;
            
            if(rides[mid][0]>=tofind)
            {
                ans=mid;
                end=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
    
    long long f(int idx,long long size,vector<vector<int>>& rides,vector<long long>&dp)
    {
        if(idx>=size)
        {
            return 0;
        }
        
        if(idx<0)
        {
            return 0;
        }
        
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }

//         for(j=idx+1;j<size;j++)
//         {
//             if(rides[j][0]>=rides[idx][1])
//             {
//                 break;
//             }
//         }
        
        int j=find(rides,idx+1,rides[idx][1]);
        
        long long take=rides[idx][1]-rides[idx][0]+rides[idx][2]+f(j,size,rides,dp);
        long long nottake=f(idx+1,size,rides,dp);
        
        return dp[idx]=max(take,nottake);
    }
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
       
        long long size=rides.size();
         vector<long long>dp(size+1,-1);
        return f(0,size,rides,dp);
    }
};