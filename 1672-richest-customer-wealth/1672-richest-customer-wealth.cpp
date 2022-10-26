class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int>sum_arr;
        for(int i=0;i<accounts.size();i++)
        {
            sum_arr.push_back(accumulate(accounts[i].begin(),accounts[i].end(),0));
        }
        int max=INT_MIN;
        for(auto x:sum_arr)
        {
            if(x>max)
            {
                max=x;
            }
        }
        
        return max;
    }
};