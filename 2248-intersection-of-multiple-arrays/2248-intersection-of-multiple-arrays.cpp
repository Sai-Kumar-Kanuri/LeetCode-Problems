class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        int n=nums.size();
        cout<<n<<endl;
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[nums[i][j]]++;
            }
        }
        vector<int>ans;
        
        for(auto x:mp)
        {
            cout<<x.first<<" "<<x.second<<endl;
            if(x.second==n)
            {
                ans.push_back(x.first);
            }
        }
        
        return ans;
        
    }
};