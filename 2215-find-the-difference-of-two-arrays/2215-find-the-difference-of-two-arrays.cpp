class Solution {
public:
    vector<int> f(vector<int>&nums1,vector<int>&nums2)
    {
        set<int> s;
        for(auto x:nums2)
        {
            s.insert(x);
        }
        set<int>ans;
        for(int i=0;i<nums1.size();i++)
        {
            if(s.find(nums1[i])==s.end())
            {
                ans.insert(nums1[i]);
            }
        }
        
        vector<int>answer(ans.begin(),ans.end());
        
        return answer;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
        
        
        return {f(nums1,nums2),f(nums2,nums1)};
    }
};