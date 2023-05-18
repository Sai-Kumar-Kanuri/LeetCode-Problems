class Solution {
public:
     static bool cmp(vector<int>&a,vector<int>&b)
    {
       
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),cmp);
        
        int cnt=0;
        int end=intervals[0][1];
        int n=intervals.size();
        
        
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]<end)
            {
                cnt++;
            }
            else{
                end=intervals[i][1];
            }
        }
        
        return cnt;
        
    }
};