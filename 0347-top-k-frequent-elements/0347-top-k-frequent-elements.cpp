class Solution {
public:
    static bool compare(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        for(auto it:nums)
        {
            mp[it]++;
        }
        
        vector<pair<int, int> > ans(mp.begin(), mp.end());
        
        sort(ans.begin(),ans.end(),compare);
        
        vector<int>final;
        
        for(int i=0;i<k;i++)
        {
            final.push_back(ans[i].first);
        }
        return final;;
    }
};