class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans=duration;
        for(int i=0;i<timeSeries.size()-1;i++)
        {
            if(timeSeries[i]+duration>timeSeries[i+1])
            {
                ans=ans+timeSeries[i+1]-timeSeries[i];
            }
            else{
                 ans+=duration;
            }  
        }
        return ans;
    }
};