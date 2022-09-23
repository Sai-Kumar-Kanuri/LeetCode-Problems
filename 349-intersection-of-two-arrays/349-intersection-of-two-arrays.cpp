class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set<int>result;
        auto ls=set_intersection(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),nums1.begin());
        for(auto it=nums1.begin();it!=ls;++it)
        {
            result.insert(*it);
        }
        vector<int>res(result.begin(),result.end());
        return res;
    }
};