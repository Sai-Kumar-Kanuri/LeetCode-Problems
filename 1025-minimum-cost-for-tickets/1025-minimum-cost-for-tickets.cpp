class Solution {
public:
    
    int f(int idx,vector<int>& days, vector<int>& costs,vector<int>& dp){
        
        if(idx>=days.size()){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int pick1 = costs[0]+f(idx+1,days,costs,dp);;
        
        
        int num = days[idx]+7;
        int idx7 = idx;
        while(idx7<days.size() && days[idx7]<num){
            idx7++;
        }
        
        int pick7 = costs[1]+f(idx7,days,costs,dp);
        
        int num1 = days[idx]+30;
        int idx30 = idx;
        while(idx30<days.size() && days[idx30]<num1){
            idx30++;
        }
        
        int pick30 = costs[2]+f(idx30,days,costs,dp);
        
        
        return dp[idx]=min({pick1,pick7,pick30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        
        return f(0,days,costs,dp);
    }
};