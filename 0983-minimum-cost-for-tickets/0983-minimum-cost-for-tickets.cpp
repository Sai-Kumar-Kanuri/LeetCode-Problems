class Solution {
public:
    int f(vector<int>& days, vector<int>& costs,int idx,vector<int>&dp)
    {
        if(idx==days.size())
        {
            return 0;
        }

        if(dp[idx]!=-1)
        {
            return dp[idx];
        }

        int take1=costs[0]+f(days,costs,idx+1,dp);

        int num=days[idx]+7;
        int idx7=idx;

        while(idx7<days.size() && days[idx7]<num )
        {
            idx7++;
        }

        int take7=costs[1]+f(days,costs,idx7,dp);

        num=days[idx]+30;
        int idx30=idx;

        while(idx30<days.size() && days[idx30]<num )
        {
            idx30++;
        }

        int take30=costs[2]+f(days,costs,idx30,dp);

        return dp[idx]=min(take1,min(take7,take30));

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return f(days,costs,0,dp);
    }
};