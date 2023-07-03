class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int>mp;
        string ans="";
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        vector<pair<int,char>>v;
        
        for(auto it : mp)
        {
            v.push_back({it.second,it.first});
        }
        
        sort(v.rbegin(), v.rend());
        
        for(auto it:v)
        {
            int d=it.first;
            for(int i=0;i<d;i++)
            {
                ans+=it.second;
            }
        }
        return ans;
    }
};